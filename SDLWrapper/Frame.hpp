#ifndef INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD

#include <span>
#include <string_view>
#include "SDLWrapper.hpp"

namespace ink::SDL {
	
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
		
	/* START CONSTRUCTION */
		
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
		operator=(Frame && rval) try {
			if (M_data != nullptr) throw "Encountered assignment to already-initiaized Frame object. Throwing intentionally.";
			std::swap(M_data, rval.M_data);
		}
		catch(const char* msg) {
			puts(msg);
			std::exit(EXIT_FAILURE);
		}
		
	/* END CONSTRUCTION */
		
		
		
	/* START SDL-API */
		
		// Return a raw pointer to the SDL_Window
		public: constexpr auto*
		window()
		{ return M_data->wnd; }
		
		// Return a raw pointer to the SDL_Renderer
		public: constexpr auto*
		renderer()
		{ return M_data->rnd; }
		
		
		
		// Return a constant reference to the event structure
		public: constexpr const auto&
		event() const
		{ return M_data->evt; }
		
		// Polls the next queued event, and returns true if there is another pending event to poll.
		public: bool
		poll_events()
		{ return internal::SDL_PollEvent( &M_data->evt ) != 0; }
		
	/* END SDL-API */
		
		
		
	/* START TEXTURE CREATION */
		
		public: Texture
		LoadTexture(std::string_view img_path)
		{ return internal::IMG::IMG_LoadTexture(renderer(), img_path.cbegin()); }
		
	/* END TEXTURE CREATION */
		
		
		
	/* START DRAW FUNCTIONS */
		
		public: constexpr ssize_t
		LastErrorCode()
		{ return M_data->last_errcode; }
		
		
		
		public: Frame&
		DrawClear()
		{ M_data->last_errcode = internal::SDL_RenderClear(renderer()); return *this; }
		
		public: Frame&
		DrawClear(internal::Uint8 r, internal::Uint8 g, internal::Uint8 b, internal::Uint8 a = 255)
		{ DrawColor(r, g, b, a); DrawClear(); return *this; }
		
		public: Frame&
		DrawClear(RGBA rgba)
		{ DrawColor(rgba); DrawClear(); return *this; }
		
		
		
		public: Frame&
		DrawColor(internal::Uint8 r, internal::Uint8 g, internal::Uint8 b, internal::Uint8 a = 255)
		{ M_data->last_errcode = internal::SDL_SetRenderDrawColor(renderer(), r, g, b, a); return *this; }
		
		public: Frame&
		DrawColor(RGBA rgba)
		{ DrawColor(rgba.r, rgba.g, rgba.b, rgba.a); return *this; }
		
		
		
		public: template<detail::arithmetic T> Frame&
		DrawPoint(T x, T y)
		{ M_data->last_errcode = detail::geometry_impl<T>::RenderDrawPoint(renderer(), x, y); return *this; }
		
		public: template<detail::arithmetic T> Frame&
		DrawPoint(std::span<Point<T>> points)
		{ M_data->last_errcode = detail::geometry_impl<T>::RenderDrawPoints(renderer(), &*points.begin(), points.size()); return *this; }
		
		public: template<detail::arithmetic T> Frame&
		DrawLine(T x1, T y1, T x2, T y2)
		{ M_data->last_errcode = detail::geometry_impl<T>::RenderDrawLine(renderer(), x1, y1, x2, y2); return *this; }
		
		public: template<detail::arithmetic T> Frame&
		DrawLine(std::span<Point<T>> points)
		{ M_data->last_errcode = detail::geometry_impl<T>::RenderDrawLines(renderer(), &*points.begin(), points.size()); return *this; }
		
		public: template<detail::arithmetic T> Frame&
		DrawRect(T x, T y, T w, T h)
		{ Rect<T> rect; M_data->last_errcode = detail::geometry_impl<T>::RenderDrawRect(renderer(), &rect); return *this; }
		
		public: template<detail::arithmetic T> Frame&
		DrawRect(std::span<Rect<T>> rects)
		{ M_data->last_errcode = detail::geometry_impl<T>::RenderDrawRects(renderer(), &*rects.begin(), rects.size()); return *this; }
		
		
		
		private: template<typename T>
		struct optional_geometry {
			
			public: constexpr
			optional_geometry(T const& cref):
			value(&cref) {}
			
			public: constexpr
			optional_geometry(std::nullptr_t null = nullptr):
			value(null) {}
			
			public: constexpr
			optional_geometry(int) = delete;
			
			T const* value = nullptr;
			
		};
		
		private: template<detail::arithmetic T> using RECT = optional_geometry<Rect<T>>;
		private: template<detail::arithmetic T> using POINT = optional_geometry<Point<T>>;
		
		/**
		 * @param tex Texture to render.
		 * @param dst Can safely be either constructed as an SDL::Rect, or as nullptr to ignore (defaults to texture { width , height }).
		 * @param src Can safely be either constructed as an SDL::Rect, or as nullptr to ignore (defaults to frame { width , height }).
		*/
		public: template<detail::arithmetic T> Frame&
		DrawTexture(Texture const& tex, RECT<T> const& dst = {}, RECT<int> const& src = {})
		{ M_data->last_errcode = detail::geometry_impl<T>::RenderCopy(renderer(), tex, src.value, dst.value); return *this; }
		
		/**
		 * @param tex Texture to render.
		 * @param dst Can safely be either constructed as an SDL::Rect, or as nullptr to ignore (defaults to frame		{ 0 , 0 , width , height }).
		 * @param src Can safely be either constructed as an SDL::Rect, or as nullptr to ignore (defaults to texture	{ 0 , 0 , width , height }).
		 * @param angle Angle of rotation at which the texture is rendered.
		 * @param center Can safely be either constructed as an SDL::Rect, or as nullptr to ignore (defaults to { dst.w /2 , dst.h/2 }).
		 * @param flip Flip state with which to render the texture.
		*/
		public: template<detail::arithmetic T> Frame&
		DrawTexture(Texture const& tex, RECT<T> const& dst, RECT<int> const& src, double angle, POINT<T> const& center = {}, Flip const& flip = Flip::SDL_FLIP_NONE)
		{ M_data->last_errcode = detail::geometry_impl<T>::RenderCopyEx(renderer(), tex, src.value, dst.value, angle, &center, flip); return *this; }
		
		
		
		public: void
		DrawUpdate()
		{ internal::SDL_RenderPresent(renderer()); }
		
	/* END DRAW FUNCTIONS */
		
		
		
		private: struct impl {
			
			internal::SDL_Event evt{};
			internal::SDL_Window* wnd{nullptr};
			internal::SDL_Renderer* rnd{nullptr};
			ssize_t last_errcode = 0;
			
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