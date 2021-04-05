#ifndef INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD

#include <stdio.h>
#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	/**
	 * This is a wrapper around the initialization and (automatic) deinitialization of the SDL library and its satellite libraries (Image, Mixer, TTF).
	 * The intended usage is as demonstrated in this example:
	 * 
	 * (function) {
	 * 	auto subsys = Subsystem<>().SDL_everything().IMG_png().init();
	 * 	[...] (any/all SDL related code) [...]
	 * }
	 * 
	 * Each method, save one, pertaining to this type toggles a component of the library it is prefixed by, and returns a new
	 * instance of the type which has the appropriate flag toggled.
	 * 
	 * The 'init' method initializes the libraries with the flags given, and returns an instance of the object that 'owns' the lifetime
	 * of the SDL libraries, which when destroyed, will deinitialize all the initialized SDL libraries. This instance should be stored as shown in the previous
	 * example, before any SDL-related code. 
	*/
	template<	internal::Uint32	sdl_flag = 0,
				int					mix_flag = 0,
				int					img_flag = 0,
				bool				ttf_flag = 0,
				bool				owning = false
	> class Subsystem {
		
		public: constexpr auto
		init() const
		{
			
			if constexpr(sdl_flag != 0) {
				internal::SDL_Init(sdl_flag);
			}
			
			if constexpr(mix_flag != 0) {
				internal::MIX::Mix_Init(mix_flag);
			}
			
			if constexpr(img_flag != 0) {
				internal::IMG::IMG_Init(img_flag);
			}
			
			if constexpr(ttf_flag) {
				internal::TTF::TTF_Init();
			}
			
			return Subsystem<sdl_flag, mix_flag, img_flag, ttf_flag, true>();
		}
		
		protected: static auto
		deinit()
		{
			if constexpr(owning) {
				
				if constexpr(owning && ttf_flag) {
					internal::TTF::TTF_Quit();
				}
				
				if constexpr(owning && img_flag != 0) {
					internal::IMG::IMG_Quit();
				}
				
				if constexpr(owning && mix_flag != 0) {
					internal::MIX::Mix_Quit();
				}
				
				if constexpr(owning && sdl_flag != 0) {
					internal::SDL_Quit();
				}
				
			}
		}
		
		public: constexpr auto
		SDL_everything						() { return Subsystem<sdl_flag ^ internal::INIT_EVERYTHING,		mix_flag,	img_flag,	ttf_flag>(); }
		
		constexpr auto SDL_timer			() { return Subsystem<sdl_flag ^ internal::INIT_TIMER,			mix_flag,	img_flag,	ttf_flag>(); }
		constexpr auto SDL_audio			() { return Subsystem<sdl_flag ^ internal::INIT_AUDIO,			mix_flag,	img_flag,	ttf_flag>(); }
		constexpr auto SDL_video			() { return Subsystem<sdl_flag ^ internal::INIT_VIDEO,			mix_flag,	img_flag,	ttf_flag>(); }
		constexpr auto SDL_joystick			() { return Subsystem<sdl_flag ^ internal::INIT_JOYSTICK,		mix_flag,	img_flag,	ttf_flag>(); }
		constexpr auto SDL_haptic			() { return Subsystem<sdl_flag ^ internal::INIT_HAPTIC,			mix_flag,	img_flag,	ttf_flag>(); }
		constexpr auto SDL_gamecontroller	() { return Subsystem<sdl_flag ^ internal::INIT_GAMECONTROLLER,	mix_flag,	img_flag,	ttf_flag>(); }
		constexpr auto SDL_events			() { return Subsystem<sdl_flag ^ internal::INIT_EVENTS,			mix_flag,	img_flag,	ttf_flag>(); }
		constexpr auto SDL_sensor			() { return Subsystem<sdl_flag ^ internal::INIT_SENSOR,			mix_flag,	img_flag,	ttf_flag>(); }
		constexpr auto SDL_noparachute		() { return Subsystem<sdl_flag ^ internal::INIT_NOPARACHUTE,	mix_flag,	img_flag,	ttf_flag>(); }
		
		
		
		public: constexpr auto
		MIX_everything						() {}
		
		constexpr auto MIX_flac				() { return Subsystem<sdl_flag,	mix_flag ^ internal::MIX::MIX_INIT_FLAC,	img_flag,	ttf_flag>(); }
		constexpr auto MIX_mod				() { return Subsystem<sdl_flag,	mix_flag ^ internal::MIX::MIX_INIT_MOD,		img_flag,	ttf_flag>(); }
		constexpr auto MIX_mp3				() { return Subsystem<sdl_flag,	mix_flag ^ internal::MIX::MIX_INIT_MP3,		img_flag,	ttf_flag>(); }
		constexpr auto MIX_ogg				() { return Subsystem<sdl_flag,	mix_flag ^ internal::MIX::MIX_INIT_OGG,		img_flag,	ttf_flag>(); }
		constexpr auto MIX_mid				() { return Subsystem<sdl_flag,	mix_flag ^ internal::MIX::MIX_INIT_MID,		img_flag,	ttf_flag>(); }
		constexpr auto MIX_opus				() { return Subsystem<sdl_flag,	mix_flag ^ internal::MIX::MIX_INIT_OPUS,	img_flag,	ttf_flag>(); }
		
		
		
		public: constexpr auto
		IMG_everything						() {}
		
		constexpr auto IMG_jpg				() { return Subsystem<sdl_flag,	mix_flag,	img_flag ^ internal::IMG::IMG_INIT_JPG,		ttf_flag>(); }
		constexpr auto IMG_png				() { return Subsystem<sdl_flag,	mix_flag,	img_flag ^ internal::IMG::IMG_INIT_PNG,		ttf_flag>(); }
		constexpr auto IMG_tif				() { return Subsystem<sdl_flag,	mix_flag,	img_flag ^ internal::IMG::IMG_INIT_TIF,		ttf_flag>(); }
		constexpr auto IMG_webp				() { return Subsystem<sdl_flag,	mix_flag,	img_flag ^ internal::IMG::IMG_INIT_WEBP,	ttf_flag>(); }
		
		
		
		public: constexpr auto
		TTF_toggle							() { return Subsystem<sdl_flag,	mix_flag,	img_flag,	!ttf_flag>(); }
		
	};
	
	template<	internal::Uint32	sdl_flag,
				int					mix_flag,
				int					img_flag,
				bool				ttf_flag
	> class	Subsystem<sdl_flag, mix_flag, img_flag, ttf_flag, true>:
	private	Subsystem<sdl_flag, mix_flag, img_flag, ttf_flag, false> {
		
		private: friend class
		Subsystem<sdl_flag, mix_flag, img_flag, ttf_flag, false>;
		
		public:
		~Subsystem() { this->deinit(); }
		
	};
	
}

#endif
