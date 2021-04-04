#ifndef INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD

#include <stdio.h>
#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	
	
	struct Subsystem {
		
		private: using
		This = Subsystem;
		
		public:
		
		This&	SDL_everything		() { M_sdl_flag ^= internal::INIT_EVERYTHING;		return *this; }
		
		This&	SDL_timer			() { M_sdl_flag ^= internal::INIT_TIMER;			return *this; }
		This&	SDL_audio			() { M_sdl_flag ^= internal::INIT_AUDIO;			return *this; }
		This&	SDL_video			() { M_sdl_flag ^= internal::INIT_VIDEO;			return *this; }
		This&	SDL_joystick		() { M_sdl_flag ^= internal::INIT_JOYSTICK;			return *this; }
		This&	SDL_haptic			() { M_sdl_flag ^= internal::INIT_HAPTIC;			return *this; }
		This&	SDL_gamecontroller	() { M_sdl_flag ^= internal::INIT_GAMECONTROLLER;	return *this; }
		This&	SDL_events			() { M_sdl_flag ^= internal::INIT_EVENTS;			return *this; }
		This&	SDL_sensor			() { M_sdl_flag ^= internal::INIT_SENSOR;			return *this; }
		This&	SDL_noparachute		() { M_sdl_flag ^= internal::INIT_NOPARACHUTE;		return *this; }
		
		
		
		This&	MIX_everything		() { return MIX_flac().MIX_mod().MIX_mp3().MIX_ogg().MIX_mid().MIX_opus(); }
		
		This&	MIX_flac			() { M_mix_flag ^= internal::MIX::MIX_INIT_FLAC;	return *this; }
		This&	MIX_mod				() { M_mix_flag ^= internal::MIX::MIX_INIT_MOD;		return *this; }
		This&	MIX_mp3				() { M_mix_flag ^= internal::MIX::MIX_INIT_MP3;		return *this; }
		This&	MIX_ogg				() { M_mix_flag ^= internal::MIX::MIX_INIT_OGG;		return *this; }
		This&	MIX_mid				() { M_mix_flag ^= internal::MIX::MIX_INIT_MID;		return *this; }
		This&	MIX_opus			() { M_mix_flag ^= internal::MIX::MIX_INIT_OPUS;	return *this; }
		
		
		
		This&	IMG_everything		() { return IMG_jpg().IMG_png().IMG_tif().IMG_webp(); }
		
		This&	IMG_jpg				() { M_img_flag ^= internal::IMG::IMG_INIT_JPG;		return *this; }
		This&	IMG_png				() { M_img_flag ^= internal::IMG::IMG_INIT_PNG;		return *this; }
		This&	IMG_tif				() { M_img_flag ^= internal::IMG::IMG_INIT_TIF;		return *this; }
		This&	IMG_webp			() { M_img_flag ^= internal::IMG::IMG_INIT_WEBP;	return *this; }
		
		
		
		This&	TTF_enable			() { M_ttf_flag = !M_ttf_flag;						return *this; }
		
		public: constexpr
		Subsystem()
		{}
		
		public:
		~Subsystem() {
			
			if (M_ttf_flag)
			{ internal::TTF::TTF_Quit(); }
			
			if (M_img_flag != 0)
			{ internal::IMG::IMG_Quit(); }
			
			if (M_mix_flag != 0)
			{ internal::MIX::Mix_Quit(); }
			
			if (M_sdl_flag != 0)
			{ internal::SDL_Quit(); }
			
		}
		
		public: void
		init()
		{
			
			if (M_sdl_flag != 0) {
				const auto out = internal::SDL_Init(M_sdl_flag);
				(out == 0) || puts(internal::SDL_GetError());
			}
			
			if (M_mix_flag != 0) {
				const auto out = internal::MIX::Mix_Init(M_mix_flag);
				(out == M_mix_flag) || puts(internal::SDL_GetError());
			}
			
			if (M_img_flag != 0) {
				const auto out = internal::IMG::IMG_Init(M_img_flag);
				(out == M_img_flag) || puts(internal::SDL_GetError());
			}
			
			if (M_ttf_flag != 0) {
				const auto out = internal::TTF::TTF_Init();
				(out == 0) || puts(internal::SDL_GetError());
			}
			
		}
		
		private: internal::Uint32	M_sdl_flag = 0;
		private: int				M_mix_flag = 0;
		private: int				M_img_flag = 0;
		private: bool				M_ttf_flag = 0;
		
	};
	
}

#endif
