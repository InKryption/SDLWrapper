#ifndef INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD

#include <span>
#include <string_view>
#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	namespace detail {
		
		static constexpr struct ignore_impl {
			
			public: constexpr operator SDL::Rect<int>() const
			{ return *static_cast<SDL::Rect<int>*>(nullptr); }
			
			public: constexpr operator SDL::Rect<float>() const
			{ return *static_cast<SDL::Rect<float>*>(nullptr); }
			
			public: constexpr operator SDL::Point<int>() const
			{ return *static_cast<SDL::Point<int>*>(nullptr); }
			
			public: constexpr operator SDL::Point<float>() const
			{ return *static_cast<SDL::Point<float>*>(nullptr); }
			
			
			
			public: constexpr operator detail::Rect<int>() const
			{ return *static_cast<detail::Rect<int>*>(nullptr); }
			
			public: constexpr operator detail::Rect<float>() const
			{ return *static_cast<detail::Rect<float>*>(nullptr); }
			
			public: constexpr operator detail::Point<int>() const
			{ return *static_cast<detail::Point<int>*>(nullptr); }
			
			public: constexpr operator detail::Point<float>() const
			{ return *static_cast<detail::Point<float>*>(nullptr); }
			
		} ignore{};
		
	}
	
	using detail::ignore;
	
	class Frame {
		
		using Texture = internal::SDL_Texture*;
		using Flip = internal::SDL_RendererFlip;
		
		private: template<internal::Uint32 wnd, internal::Uint32 rnd>
		struct FlagCtr {
					
			constexpr auto FULLSCREEN		()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_FULLSCREEN			,	rnd		>(); }
			constexpr auto OPENGL			()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_OPENGL				,	rnd		>(); }
			constexpr auto HIDDEN			()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_HIDDEN				,	rnd		>(); }
			constexpr auto BORDERLESS		()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_BORDERLESS			,	rnd		>(); }
			constexpr auto RESIZABLE		()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_RESIZABLE			,	rnd		>(); }
			constexpr auto MAXIMIZED		()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_MAXIMIZED			,	rnd		>(); }
			constexpr auto MINIMIZED		()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_MINIMIZED			,	rnd		>(); }
			constexpr auto INPUT_GRABBED	()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_INPUT_GRABBED		,	rnd		>(); }
			constexpr auto ALLOW_HIGHDPI	()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_ALLOW_HIGHDPI		,	rnd		>(); }
			constexpr auto VULKAN			()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_VULKAN				,	rnd		>(); }
			constexpr auto METAL			()	{ return FlagCtr<	wnd	^	internal::SDL_WINDOW_METAL				,	rnd		>(); }
					
			constexpr auto SOFTWARE			()	{ return FlagCtr<	wnd	,	internal::SDL_RENDERER_SOFTWARE			^	rnd		>(); }
			constexpr auto ACCELERATED		()	{ return FlagCtr<	wnd	,	internal::SDL_RENDERER_ACCELERATED		^	rnd		>(); }
			constexpr auto PRESENTVSYNC		()	{ return FlagCtr<	wnd	,	internal::SDL_RENDERER_PRESENTVSYNC		^	rnd		>(); }
			constexpr auto TARGETTEXTURE	()	{ return FlagCtr<	wnd	,	internal::SDL_RENDERER_TARGETTEXTURE	^	rnd		>(); }
			
		};
		
		// Return base template for creating window flags. Each function of this object returns an appropriately configured "Flag Struct",
		// which can be passed to the Frame constructor to set said flags, allowing for chaining of functions. e.g. "SDL::Frame::MakeFlags().ACCELERATED().RESIZABLE()"
		public: static constexpr auto
		MakeFlags()
		{ return FlagCtr<0,0>(); }
		
		public: constexpr
		Frame()
		{}
		
		public:
		Frame(Frame const&) = delete;
		
		// Construct flags with FlagCtr using the "SDL::Frame::MakeFlags()" static method.
		public: template<internal::Uint32 wnd, internal::Uint32 rnd> [[nodiscard]] 
		Frame(std::string_view title, int w, int h, [[maybe_unused]] FlagCtr<wnd, rnd> f = FlagCtr<0,0>(), int x = internal::WINDOWPOS_UNDEFINED, int y = internal::WINDOWPOS_UNDEFINED, int render_driver = -1)
		{
			( M_data = new impl{} )
				->init(title.cbegin(), x, y, w, h, wnd, render_driver, rnd);
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
		
		
		
		public: template<detail::arithmetic T> auto
		DrawTexture(Texture const& tex)
		{ return detail::geometry_impl<T>::RenderCopy(renderer(), tex, nullptr, nullptr); }
		
		public: template<detail::arithmetic T> auto
		DrawTexture(Texture const& tex, Rect<T> const& dst, Rect<int> const& src = ignore)
		{ return detail::geometry_impl<T>::RenderCopy(renderer(), tex, &src, &dst); }
		
		public: template<detail::arithmetic T> auto
		DrawTexture(Texture const& tex, Rect<T> const& dst, Rect<int> const& src, double angle, Point<T> const& center = ignore, Flip const& flip = Flip::SDL_FLIP_NONE)
		{ return detail::geometry_impl<T>::RenderCopyEx(renderer(), tex, &src, &dst, angle, &center, flip); }
		
		
		
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
