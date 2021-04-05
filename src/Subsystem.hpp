#ifndef INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD

#include <stdio.h>
#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	
	/**
	 * This is a simple wrapper around the initialization of the SDL library and its satellite libraries (Image, Mixer, TTF).
	 * 
	 * The intended purpose of type is essentially to construct a single instance of it, preferably at the beginning, and top-level
	 * of the program, such that it is constructed and configured before anything SDL-related, and is the last to be popped off
	 * the stack, which is when it will automatically de-initialize all SDL-related libraries.
	*/
	// 
	// class Subsystem {
	// 	
	// 	private: using
	// 	This = Subsystem;
	// 	
	// 	public: void
	// 	init()
	// 	{
	// 		
	// 		if (M_sdl_flag != 0) {
	// 			const auto out = internal::SDL_Init(M_sdl_flag);
	// 			(out == 0) || puts(internal::SDL_GetError());
	// 		}
	// 		
	// 		if (M_mix_flag != 0) {
	// 			const auto out = internal::MIX::Mix_Init(M_mix_flag);
	// 			(out == M_mix_flag) || puts(internal::SDL_GetError());
	// 		}
	// 		
	// 		if (M_img_flag != 0) {
	// 			const auto out = internal::IMG::IMG_Init(M_img_flag);
	// 			(out == M_img_flag) || puts(internal::SDL_GetError());
	// 		}
	// 		
	// 		if constexpr(M_ttf_flag != 0) {
	// 			const auto out = internal::TTF::TTF_Init();
	// 			(out == 0) || puts(internal::SDL_GetError());
	// 		}
	// 		
	// 	}
	// 	
	// 	public:
	// 	
	// 	This&	SDL_everything		() { M_sdl_flag ^= internal::INIT_EVERYTHING;		return *this; }
	// 	
	// 	This&	SDL_timer			() { M_sdl_flag ^= internal::INIT_TIMER;			return *this; }
	// 	This&	SDL_audio			() { M_sdl_flag ^= internal::INIT_AUDIO;			return *this; }
	// 	This&	SDL_video			() { M_sdl_flag ^= internal::INIT_VIDEO;			return *this; }
	// 	This&	SDL_joystick		() { M_sdl_flag ^= internal::INIT_JOYSTICK;			return *this; }
	// 	This&	SDL_haptic			() { M_sdl_flag ^= internal::INIT_HAPTIC;			return *this; }
	// 	This&	SDL_gamecontroller	() { M_sdl_flag ^= internal::INIT_GAMECONTROLLER;	return *this; }
	// 	This&	SDL_events			() { M_sdl_flag ^= internal::INIT_EVENTS;			return *this; }
	// 	This&	SDL_sensor			() { M_sdl_flag ^= internal::INIT_SENSOR;			return *this; }
	// 	This&	SDL_noparachute		() { M_sdl_flag ^= internal::INIT_NOPARACHUTE;		return *this; }
	// 	
	// 	
	// 	
	// 	This&	MIX_everything		() { return MIX_flac().MIX_mod().MIX_mp3().MIX_ogg().MIX_mid().MIX_opus(); }
	// 	
	// 	This&	MIX_flac			() { M_mix_flag ^= internal::MIX::MIX_INIT_FLAC;	return *this; }
	// 	This&	MIX_mod				() { M_mix_flag ^= internal::MIX::MIX_INIT_MOD;		return *this; }
	// 	This&	MIX_mp3				() { M_mix_flag ^= internal::MIX::MIX_INIT_MP3;		return *this; }
	// 	This&	MIX_ogg				() { M_mix_flag ^= internal::MIX::MIX_INIT_OGG;		return *this; }
	// 	This&	MIX_mid				() { M_mix_flag ^= internal::MIX::MIX_INIT_MID;		return *this; }
	// 	This&	MIX_opus			() { M_mix_flag ^= internal::MIX::MIX_INIT_OPUS;	return *this; }
	// 	
	// 	
	// 	
	// 	This&	IMG_everything		() { return IMG_jpg().IMG_png().IMG_tif().IMG_webp(); }
	// 	
	// 	This&	IMG_jpg				() { M_img_flag ^= internal::IMG::IMG_INIT_JPG;		return *this; }
	// 	This&	IMG_png				() { M_img_flag ^= internal::IMG::IMG_INIT_PNG;		return *this; }
	// 	This&	IMG_tif				() { M_img_flag ^= internal::IMG::IMG_INIT_TIF;		return *this; }
	// 	This&	IMG_webp			() { M_img_flag ^= internal::IMG::IMG_INIT_WEBP;	return *this; }
	// 	
	// 	
	// 	
	// 	This&	TTF_enable			() { M_ttf_flag = !M_ttf_flag;						return *this; }
	// 	
	// 	public: constexpr
	// 	Subsystem()
	// 	{}
	// 	
	// 	public:
	// 	~Subsystem() {
	// 		
	// 		if (M_ttf_flag)
	// 		{ internal::TTF::TTF_Quit(); }
	// 		
	// 		if (M_img_flag != 0)
	// 		{ internal::IMG::IMG_Quit(); }
	// 		
	// 		if (M_mix_flag != 0)
	// 		{ internal::MIX::Mix_Quit(); }
	// 		
	// 		if (M_sdl_flag != 0)
	// 		{ internal::SDL_Quit(); }
	// 		
	// 	}
	// 	
	// 	public: Subsystem(This const&) = delete;
	// 	public: Subsystem(This &&) = delete;
	// 	
	// 	private: internal::Uint32	M_sdl_flag = 0;
	// 	private: int				M_mix_flag = 0;
	// 	private: int				M_img_flag = 0;
	// 	private: bool				M_ttf_flag = 0;
	// 	
	// };
	// 
	
	
	
	namespace detail {
		
		
		/**
		 * This is a wrapper around the initialization and (automatic) deinitialization of the SDL library and its satellite libraries (Image, Mixer, TTF).
		*/
		template<	internal::Uint32	sdl_flag = 0,
					int					mix_flag = 0,
					int					img_flag = 0,
					bool				ttf_flag = 0,
					bool				owning = false
		> class Subsystem {
			
			public: constexpr
			Subsystem()
			{}
			
			public:
			~Subsystem()
			{ deinit(); }
			
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
			
			private: static auto
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
		
		//template<	internal::Uint32	sdl_flag,
		//			int					mix_flag,
		//			int					img_flag,
		//			bool				ttf_flag
		//> class Subsystem<sdl_flag, mix_flag, img_flag, ttf_flag, true>: public Subsystem<sdl_flag, mix_flag, img_flag, ttf_flag, false> {
			
		//	private: friend class Subsystem<sdl_flag, mix_flag, img_flag, ttf_flag, false>;
			
		//	private: constexpr
		//	Subsystem() {}
			
		//};
	}
	
	using Subsystem = detail::Subsystem<>;
	
}

#endif
