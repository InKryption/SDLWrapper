#ifndef INK_SDLWRAPPER_MAIN_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_MAIN_HEADER_FILE_GUARD

#include <string_view>
#include "includes_undefs.hpp"

namespace ink::SDL {
		
	namespace detail {
		
		template<
			internal::Uint32 sdl = 0,
			int img = 0,
			int mix = 0,
			bool ttf = false,
			bool owning = false
		> struct SDL {
			
			private: template<decltype(sdl) _sdl = sdl, decltype(img) _img = img, decltype(mix) _mix = mix, decltype(ttf) _ttf = ttf, decltype(owning) _o = owning>
			using configure = SDL<_sdl | sdl, _img | img, _mix | mix, _ttf | ttf, _o | owning>;
			
			public: constexpr auto SDL_everything()		const
			{ return configure<internal::INIT_EVERYTHING>(); }
			
			public: constexpr auto SDL_timer()			const
			{ return configure<internal::INIT_TIMER>(); }
			
			public: constexpr auto SDL_audio()			const
			{ return configure<internal::INIT_AUDIO>(); }
			
			public: constexpr auto SDL_video()			const
			{ return configure<internal::INIT_VIDEO>().SDL_events(); }
			
			public: constexpr auto SDL_joystick()		const
			{ return configure<internal::INIT_JOYSTICK>().SDL_events(); }
			
			public: constexpr auto SDL_haptic()			const
			{ return configure<internal::INIT_HAPTIC>(); }
			
			public: constexpr auto SDL_gamecontroller()	const
			{ return configure<internal::INIT_GAMECONTROLLER>().SDL_joystick(); }
			
			public: constexpr auto SDL_events()			const
			{ return configure<internal::INIT_EVENTS>(); }
			
			public: constexpr auto SDL_sensor()			const
			{ return configure<internal::INIT_SENSOR>(); }
			
			// Legacy. SDL ignores this flag, but left in, just in case.
			public: constexpr auto SDL_noparachute()	const
			{ return configure<internal::INIT_NOPARACHUTE>(); }
			
			
			
			public: constexpr auto IMG_everything()		const
			{ return IMG_jpg().IMG_png().IMG_tif().IMG_webp(); }
			
			public: constexpr auto IMG_jpg()			const
			{ return configure<sdl, internal::IMG::IMG_INIT_JPG>(); }
			
			public: constexpr auto IMG_png()			const
			{ return configure<sdl, internal::IMG::IMG_INIT_PNG>(); }
			
			public: constexpr auto IMG_tif()			const
			{ return configure<sdl, internal::IMG::IMG_INIT_TIF>(); }
			
			public: constexpr auto IMG_webp()			const
			{ return configure<sdl, internal::IMG::IMG_INIT_WEBP>(); }
			
			
			
			public: constexpr auto MIX_everything()		const
			{ return MIX_flac().MIX_mod().MIX_mp3().MIX_ogg().MIX_mid().MIX_opus(); }
			
			public: constexpr auto MIX_flac()			const
			{ return configure<sdl, img, internal::MIX::MIX_INIT_FLAC>(); }
			
			public: constexpr auto MIX_mod()			const
			{ return configure<sdl, img, internal::MIX::MIX_INIT_MOD>(); }
			
			public: constexpr auto MIX_mp3()			const
			{ return configure<sdl, img, internal::MIX::MIX_INIT_MP3>(); }
			
			public: constexpr auto MIX_ogg()			const
			{ return configure<sdl, img, internal::MIX::MIX_INIT_OGG>(); }
			
			public: constexpr auto MIX_mid()			const
			{ return configure<sdl, img, internal::MIX::MIX_INIT_MID>(); }
			
			public: constexpr auto MIX_opus()			const
			{ return configure<sdl, img, internal::MIX::MIX_INIT_OPUS>(); }
			
			
			
			public: constexpr auto TTF_enable()			const
			{ return configure<sdl, img, mix, true>(); }
			
			
			
			template<internal::Uint32, int, int, bool, bool> friend struct SDL;
			
			public:		explicit constexpr SDL()			requires(sdl + img + mix + ttf + owning == 0) {}
			private:	explicit constexpr SDL()			requires(sdl + img + mix + ttf + owning != 0) {}
			private:	explicit constexpr SDL(SDL &&)		= delete;
			private:	explicit constexpr SDL(SDL const&)	= delete;
			
			public: constexpr configure<sdl, img, mix, ttf, true> Init() {
				if constexpr(sdl != 0) { internal::			SDL_Init(sdl); }
				if constexpr(img != 0) { internal::IMG::	IMG_Init(img); }
				if constexpr(mix != 0) { internal::MIX::	Mix_Init(mix); }
				if constexpr(ttf != 0) { internal::TTF::	TTF_Init(); }
				return configure<sdl, img, mix, ttf, true>();
			}
			
		};
		
		template<
			internal::Uint32 sdl_lib,
			int img_lib,
			int mix_lib,
			bool ttf_lib
		> struct SDL<sdl_lib, img_lib, mix_lib, ttf_lib, true> {
			
			template<internal::Uint32, int, int, bool, bool>
			friend struct SDL;
			
			public: struct
			Window {
				friend struct SDL;
				private: internal::SDL_Window* value = nullptr;
			};
			
			public: struct
			Renderer {
				friend struct SDL;
				private: internal::SDL_Renderer* value = nullptr;
			};
			
			
			
			private: template<internal::Uint32 Flags = 0> requires((sdl_lib & internal::INIT_VIDEO) != 0) struct
			WindowMaker {
				friend struct SDL;
				
				private: template<internal::Uint32 flags> using
				configure = WindowMaker<flags | Flags>;
				
				private:	constexpr	WindowMaker() {}
				public:		constexpr	WindowMaker() requires(Flags == 0) {}
				
				public: decltype(auto) Init(std::string_view title, int x, int y, int w, int h) const
				{ Window out; out.value = internal::SDL_CreateWindow(title.cbegin(), x, y, w, h, Flags); return out; }
				
				public: constexpr decltype(auto) fullscreen()		const
				{ return configure<internal::SDL_WINDOW_FULLSCREEN>(); }
				
				public: constexpr decltype(auto) opengl()			const
				{ return configure<internal::SDL_WINDOW_OPENGL>(); }
				
				public: constexpr decltype(auto) hidden()			const
				{ return configure<internal::SDL_WINDOW_HIDDEN>(); }
				
				public: constexpr decltype(auto) borderless()		const
				{ return configure<internal::SDL_WINDOW_BORDERLESS>(); }
				
				public: constexpr decltype(auto) resizable()		const
				{ return configure<internal::SDL_WINDOW_RESIZABLE>(); }
				
				public: constexpr decltype(auto) maximized()		const
				{ return configure<internal::SDL_WINDOW_MAXIMIZED>(); }
				
				public: constexpr decltype(auto) minimized()		const
				{ return configure<internal::SDL_WINDOW_MINIMIZED>(); }
				
				public: constexpr decltype(auto) input_grabbed()	const
				{ return configure<internal::SDL_WINDOW_INPUT_GRABBED>(); }
				
				public: constexpr decltype(auto) allow_highdpi()	const
				{ return configure<internal::SDL_WINDOW_ALLOW_HIGHDPI>(); }
				
				public: constexpr decltype(auto) vulkan()			const
				{ return configure<internal::SDL_WINDOW_VULKAN>(); }
				
				public: constexpr decltype(auto) metal()			const
				{ return configure<internal::SDL_WINDOW_METAL>(); }
				
			};
			
			private: template<internal::Uint32 Flags = 0> requires((sdl_lib & internal::INIT_VIDEO) != 0) struct
			RendererMaker {
				friend struct SDL;
				
				private: template<internal::Uint32 flags> using
				configure = RendererMaker<flags | Flags>;
				
				private:	constexpr	RendererMaker() {}
				public:		constexpr	RendererMaker() requires(Flags == 0) {}
				
				public: decltype(auto) Init(Window window, int rendererDriver = -1) const
				{ Renderer out; out.value = internal::SDL_CreateRenderer(window.value, rendererDriver, Flags); return out; }
				
				public: constexpr decltype(auto) software()			const
				{ return configure<internal::SDL_RENDERER_SOFTWARE>(); }
				
				public: constexpr decltype(auto) accelerated()		const
				{ return configure<internal::SDL_RENDERER_ACCELERATED>(); }
				
				public: constexpr decltype(auto) presentvsync()		const
				{ return configure<internal::SDL_RENDERER_PRESENTVSYNC>(); }
				
				public: constexpr decltype(auto) targettexture()	const
				{ return configure<internal::SDL_RENDERER_TARGETTEXTURE>(); }
				
			};
			
			
			
			// Returns a helper struct, which can be used to configure and create a window.
			public: decltype(auto)
			CreateWindow() const
			{ return WindowMaker<0>(); }
			
			// Returns a helper struct, which can be used to configure and create a renderer.
			public: decltype(auto)
			CreateRenderer() const
			{ return RendererMaker<0>(); }
			
			
			
			// Destructor manages the de-initialization of the library in many various aspects.
			public: constexpr
			~SDL() {
				
				/* Destroy windows and associated renderers */ {
					internal::SDL_Window* wnd = nullptr;
					internal::SDL_Renderer* rnd = nullptr;
					internal::Uint32 id = 1;
					while( (wnd = internal::SDL_GetWindowFromID(id++)) != nullptr ) {
						if ( (rnd = internal::SDL_GetRenderer(wnd)) != nullptr)
						{ internal::SDL_DestroyRenderer(rnd); printf("Destroyed renderer associated to window with ID %llu\n", id - 1); }
						internal::SDL_DestroyWindow(wnd);
						printf("Destroyed window ID %llu\n", id - 1);
					}
				}
				
				if constexpr(ttf_lib != 0) { internal::TTF::	TTF_Quit(); }
				if constexpr(mix_lib != 0) { internal::MIX::	Mix_Quit(); }
				if constexpr(img_lib != 0) { internal::IMG::	IMG_Quit(); }
				if constexpr(sdl_lib != 0) { internal::			SDL_Quit(); }
				
			}
			
			
			
			// Some implementation details for construction and lifetime
			
			public:		constexpr	SDL(SDL const&) = delete;
			public:		constexpr	SDL(SDL &&) = delete;
			private:	constexpr	SDL() {}
			
			
		};
		
	}
	
	using SDL = detail::SDL<>;
	
}

#endif
