#ifndef INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD

#include <stdio.h>
#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	
	
	struct Subsystem {
		
		public: struct FlagCtr {
			
			using This = FlagCtr;
			
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
			
			private: internal::Uint32	M_sdl_flag = 0;
			private: int				M_mix_flag = 0;
			private: int				M_img_flag = 0;
			private: bool				M_ttf_flag = 0;
		};
		
		public: constexpr
		Subsystem() {}
		
		public: void init(FlagCtr const&)
		{
			
		}
		
		private: bool
			sdl = false,
			mix = false,
			img = false,
			ttf = false
		;
		
	};
	
}

#endif
