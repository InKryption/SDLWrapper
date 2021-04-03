#ifndef INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_SUBSYSTEM_STRUCT_HEADER_FILE_GUARD

#include <stdio.h>
#include "Undefs.hpp"

namespace ink::SDL {
	
	/**
	 * Subsystems initialization and automatic-deinitialization wrapper.
	 * 
	 * Each function is prefixed with the library whose flag it pertains to, as in
	 * SDL_ for the main library, TTF_ for the ttf library, IMG_for the image library, MIX_ for the mixer library.
	 * 
	 * Each one returns a reference to the Subsystem instance, and is therefore chainable ( e.g. SDL_timer().SDL_audio().[...] ), all except for
	 * init(), which returns void.
	 * 
	 * Each function toggles its named flag to the opposite state. All flags are off by default. If a library has no flags enabled, it will not be initialized. 
	 * 
	 * On destruction, all libraries will be automatically de-initialized,
	 * so it is best to construct this only at the top-level of any given SDL-related functionality of a program.
	 * 
	 * CAUTION: using *_everything will toggle all pertaining flags that are enabled off, and all pretaining flags that are disabled on.
	*/
	struct Subsystem {
		
		private: using
		flagT = internal::Uint32;
		
		public: void
		init()
		{
			std::string error_msgs;
			bool success = true;
			auto append_err = [&](auto expected, auto got) constexpr {
				error_msgs += "Expected '" + std::to_string(expected) + "', got '" + std::to_string(got) + "'. SDL Error Message:\n" + internal::SDL_GetError();
			};
			
			if (M_sdl_flag != 0) {
				auto ret = internal::SDL_Init(M_sdl_flag);
				success = 0 == ret;
				append_err(0, ret);
			}
			
			if (M_mix_flag != 0) {
				auto ret = internal::MIX::Mix_Init(M_mix_flag);
				success = M_mix_flag == ret;
				append_err(M_mix_flag, ret);
			}
			
			if (M_img_flag != 0) {
				auto ret = internal::IMG::IMG_Init(M_img_flag);
				success = M_img_flag == ret;
				append_err(M_img_flag, ret);
			}
			
			if (M_ttf_flag) {
				auto ret = internal::TTF::TTF_Init();
				success = 0 == ret;
				append_err(0, ret);
			}
			
			if (!success) {
				perror(error_msgs.c_str());
				throw;
			}
			
		}
		
		
		
		// Toggles everything. Only recommended to be used alone, or as the first in the chain, as it toggles everything.
		public: auto&
		toggle_all()&
		{
			return	 SDL_everything()
					.IMG_everything()
					.MIX_everything()
					.TTF_toggle()
			;
		}
		
		
		
		public: Subsystem&
		TTF_toggle()&
		{ M_ttf_flag = !M_ttf_flag; return *this; }
		
		
		
		public: Subsystem&
		IMG_everything()&
		{ return IMG_JPG().IMG_PNG().IMG_TIF().IMG_WEBP(); }
		
		public: Subsystem&
		IMG_JPG()&
		{ toggleIMG(internal::IMG::IMG_INIT_JPG); return *this; }
		
		public: Subsystem&
		IMG_PNG()&
		{ toggleIMG(internal::IMG::IMG_INIT_PNG); return *this; }
		
		public: Subsystem&
		IMG_TIF()&
		{ toggleIMG(internal::IMG::IMG_INIT_TIF); return *this; }
		
		public: Subsystem&
		IMG_WEBP()&
		{ toggleIMG(internal::IMG::IMG_INIT_WEBP); return *this; }
		
		
		
		public: Subsystem&
		MIX_everything()&
		{ return MIX_FLAC().MIX_MOD().MIX_MP3().MIX_OGG().MIX_MID().MIX_OPUS(); }
		
		public: Subsystem&
		MIX_FLAC()&
		{ return toggleMIX(internal::MIX::MIX_INIT_FLAC); }
		
		public: Subsystem&
		MIX_MOD()&
		{ return toggleMIX(internal::MIX::MIX_INIT_MOD); }
		
		public: Subsystem&
		MIX_MP3()&
		{ return toggleMIX(internal::MIX::MIX_INIT_MP3); }
		
		public: Subsystem&
		MIX_OGG()&
		{ return toggleMIX(internal::MIX::MIX_INIT_OGG); }
		
		public: Subsystem&
		MIX_MID()&
		{ return toggleMIX(internal::MIX::MIX_INIT_MID); }
		
		public: Subsystem&
		MIX_OPUS()&
		{ return toggleMIX(internal::MIX::MIX_INIT_OPUS); }
		
		
		
		public: Subsystem&
		SDL_everything()&
		{ return toggleSDL(internal::INIT_EVERYTHING); }
		
		public: Subsystem&
		SDL_timer()&
		{ return toggleSDL(internal::INIT_TIMER); }
		
		public: Subsystem&
		SDL_audio()&
		{ return toggleSDL(internal::INIT_AUDIO); }
		
		public: Subsystem&
		SDL_video()&
		{ return toggleSDL(internal::INIT_VIDEO); }
		
		public: Subsystem&
		SDL_joystick()&
		{ return toggleSDL(internal::INIT_JOYSTICK); }
		
		public: Subsystem&
		SDL_haptic()&
		{ return toggleSDL(internal::INIT_HAPTIC); }
		
		public: Subsystem&
		SDL_gamecontroller()&
		{ return toggleSDL(internal::INIT_GAMECONTROLLER); }
		
		public: Subsystem&
		SDL_events()&
		{ return toggleSDL(internal::INIT_EVENTS); }
		
		public: Subsystem&
		SDL_sensor()&
		{ return toggleSDL(internal::INIT_SENSOR); }
		
		public: Subsystem&
		SDL_noparachute()&
		{ return toggleSDL(internal::INIT_NOPARACHUTE); }
		
		
		
		private: flagT M_sdl_flag = 0;
		Subsystem& toggleSDL(flagT flag)
		{ M_sdl_flag ^= flag; return *this; }
		
		private: int M_mix_flag = 0;
		Subsystem& toggleMIX(int flag)
		{ M_mix_flag ^= flag; return *this; }
		
		private: int M_img_flag = 0;
		Subsystem& toggleIMG(int flag)
		{ M_img_flag ^= flag; return *this; }
		
		private: bool M_ttf_flag = false;
		
	};
	
}

#endif
