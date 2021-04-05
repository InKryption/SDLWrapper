#ifndef INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD

#include <span>
#include <string_view>
#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	class Frame;
	template<> struct FlagCtr<Frame> {
		constexpr FlagCtr() {}
		
		constexpr FlagCtr& FULLSCREEN		()	{ wnd_flag ^= internal::SDL_WINDOW_FULLSCREEN;		return *this; }
		constexpr FlagCtr& OPENGL			()	{ wnd_flag ^= internal::SDL_WINDOW_OPENGL;			return *this; }
		constexpr FlagCtr& HIDDEN			()	{ wnd_flag ^= internal::SDL_WINDOW_HIDDEN;			return *this; }
		constexpr FlagCtr& BORDERLESS		()	{ wnd_flag ^= internal::SDL_WINDOW_BORDERLESS;		return *this; }
		constexpr FlagCtr& RESIZABLE		()	{ wnd_flag ^= internal::SDL_WINDOW_RESIZABLE;		return *this; }
		constexpr FlagCtr& MAXIMIZED		()	{ wnd_flag ^= internal::SDL_WINDOW_MAXIMIZED;		return *this; }
		constexpr FlagCtr& MINIMIZED		()	{ wnd_flag ^= internal::SDL_WINDOW_MINIMIZED;		return *this; }
		constexpr FlagCtr& INPUT_GRABBED	()	{ wnd_flag ^= internal::SDL_WINDOW_INPUT_GRABBED;	return *this; }
		constexpr FlagCtr& ALLOW_HIGHDPI	()	{ wnd_flag ^= internal::SDL_WINDOW_ALLOW_HIGHDPI;	return *this; }
		constexpr FlagCtr& VULKAN			()	{ wnd_flag ^= internal::SDL_WINDOW_VULKAN;			return *this; }
		constexpr FlagCtr& METAL			()	{ wnd_flag ^= internal::SDL_WINDOW_METAL;			return *this; }
		
		constexpr FlagCtr& SOFTWARE			()	{ rnd_flag ^= internal::SDL_RENDERER_SOFTWARE;		return *this; }
		constexpr FlagCtr& ACCELERATED		()	{ rnd_flag ^= internal::SDL_RENDERER_ACCELERATED;	return *this; }
		constexpr FlagCtr& PRESENTVSYNC		()	{ rnd_flag ^= internal::SDL_RENDERER_PRESENTVSYNC;	return *this; }
		constexpr FlagCtr& TARGETTEXTURE	()	{ rnd_flag ^= internal::SDL_RENDERER_TARGETTEXTURE;	return *this; }
		
		internal::Uint32 wnd_flag{0}, rnd_flag{0};
	};
	
	using FlagCtr_Frame = FlagCtr<Frame>;
	
	class Frame {
		
		public: constexpr
		Frame()
		{}
		
		public:
		Frame(Frame const&) = delete;
		
		public: [[nodiscard]]
		Frame(std::string_view title, int w, int h, FlagCtr_Frame const& flag_struct, int x = internal::WINDOWPOS_UNDEFINED, int y = internal::WINDOWPOS_UNDEFINED, int render_driver = -1)
		{
			( M_data = new impl{} )
				->init(title.cbegin(), x, y, w, h, flag_struct.wnd_flag, render_driver, flag_struct.rnd_flag);
		}
		
		public:
		~Frame()
		{ delete M_data; M_data = nullptr; }
		
		
		
		// Move will throw if acting as assignment to already-initialized Frame.
		public: void
		operator=(Frame && rval) try
		{
			if (M_data != nullptr) throw "Encountered assignment to already-initiaized Frame object. Throwing intentionally.";
			std::swap(M_data, rval.M_data);
		}
		catch(const char* msg) {
			puts(msg);
			std::exit(EXIT_FAILURE);
		}
		
		
		
		// Return a raw pointer to the SDL_Window
		public: constexpr auto*
		window() {
			return M_data->wnd;
		}
		
		// Return a raw pointer to the SDL_Renderer
		public: constexpr auto*
		renderer() {
			return M_data->rnd;
		}
		
		
		
		// Return a constant reference to the event structure
		public: constexpr const auto&
		event() const {
			return M_data->evt;
		}
		
		// Polls the next queued event, and returns true if there is another pending event to poll.
		public: bool
		poll_events() {
			return internal::SDL_PollEvent( &M_data->evt ) != 0;
		}
		
		
		
		public: auto
		DrawClear()
		{ return internal::SDL_RenderClear(renderer()); }
		
		public: auto
		DrawClear(internal::Uint8 r, internal::Uint8 g, internal::Uint8 b, internal::Uint8 a = 255)
		{ return DrawColor(r, g, b, a) & DrawClear(); }
		
		public: auto
		DrawClear(RGBA rgba)
		{ return DrawColor(rgba) & DrawClear(); }
		
		
		
		public: int
		DrawColor(internal::Uint8 r, internal::Uint8 g, internal::Uint8 b, internal::Uint8 a = 255)
		{ return internal::SDL_SetRenderDrawColor(renderer(), r, g, b, a); }
		
		public: int
		DrawColor(RGBA rgba)
		{ return DrawColor(rgba.r, rgba.g, rgba.b, rgba.a); }
		
		
		
		public: template<detail::arithmetic T> auto
		DrawPoint(T x, T y)
		{ return detail::geometry_impl<T>::RenderDrawPoint(renderer(), x, y); }
		
		public: template<detail::arithmetic T> int
		DrawPoints(std::span<Point<T>> points)
		{ return detail::geometry_impl<T>::RenderDrawPoints(renderer(), &*points.begin(), points.size()); }
		
		public: template<detail::arithmetic T> auto
		DrawLine(T x1, T y1, T x2, T y2)
		{ return detail::geometry_impl<T>::RenderDrawLine(renderer(), x1, y1, x2, y2); }
		
		public: template<detail::arithmetic T> auto
		DrawLines(std::span<Point<T>> points)
		{ return detail::geometry_impl<T>::RenderDrawLines(renderer(), &*points.begin(), points.size()); }
		
		public: template<detail::arithmetic T> auto
		DrawRect(T x, T y, T w, T h)
		{ Rect<T> rect; return detail::geometry_impl<T>::RenderDrawRect(renderer(), &rect); }
		
		public: template<detail::arithmetic T> auto
		DrawRects(std::span<Rect<T>> rects)
		{ return detail::geometry_impl<T>::RenderDrawRects(renderer(), &*rects.begin(), rects.size()); }
		
		
		
		public: auto
		DrawUpdate()
		{ return internal::SDL_RenderPresent(renderer()); }
		
		
		
		private: struct impl {
			
			internal::SDL_Event evt{};
			internal::SDL_Window* wnd{nullptr};
			internal::SDL_Renderer* rnd{nullptr};
			internal::SDL_WindowFlags f;
			void init(	char const* title,
						int x, int y, int w, int h,
						ink::SDL::internal::Uint32 wnd_flags,
						int render_driver,
						ink::SDL::internal::Uint32 rnd_flags) {
				
				wnd = internal::SDL_CreateWindow(title, x, y, w, h, wnd_flags);
				rnd = internal::SDL_CreateRenderer(wnd, render_driver, rnd_flags);
				evt = internal::SDL_Event{};
				
			}
			
			void deinit() {
				internal::SDL_DestroyRenderer(rnd);
				internal::SDL_DestroyWindow(wnd);
			}
			
		}* M_data{nullptr};
		
	};
	
}

#endif
