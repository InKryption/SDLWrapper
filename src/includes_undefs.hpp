#ifndef INK_SDLWRAPPER_UNDEFINITIONS_MACRO_CLEANUP_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_UNDEFINITIONS_MACRO_CLEANUP_HEADER_FILE_GUARD

#include <cstdlib>

namespace ink::SDL {
	
	namespace internal {
		
		#define SDL_assert_h_ // Decided that this is too much of a pain to set up, and also just kind of extends assert.h. I may reconsider, but not for now
		#define SDL_atomic_h_ // Duplicates the standard library. Also, too lazy to actually go through the trouble of cleaning up the macros
		#define SDL_mutex_h_ // See above comment.
		#define SDL_thread_h_ // Holy shit fuck this one
		
		#include <SDL2/SDL.h>
		
		namespace MIX {
			#include <SDL2/SDL_mixer.h>
			#include "Undefs/unSDL_mixer.h"
		}
		
		namespace IMG {
			#include <SDL2/SDL_image.h>
			#include "Undefs/unSDL_image.h"
		}
		
		namespace TTF {
			#include "SDL2/SDL_ttf.h"
			#include "Undefs/unSDL_ttf.h"
		}
		
		#include "Undefs/unSDL.h"
		#include "Undefs/unSDL_main.h"
		#include "Undefs/unSDL_stdinc.h"
		#include "Undefs/unSDL_audio.h"
		#include "Undefs/unSDL_cpuinfo.h"
		#include "Undefs/unSDL_endian.h"
		#include "Undefs/unSDL_error.h"
		#include "Undefs/unSDL_events.h"
		#include "Undefs/unSDL_gamecontroller.h"
		#include "Undefs/unSDL_haptic.h"
		#include "Undefs/unSDL_hints.h"
		#include "Undefs/unSDL_joystick.h"
		#include "Undefs/unSDL_log.h"
		#include "Undefs/unSDL_rwops.h"
		#include "Undefs/unSDL_sensor.h"
		#include "Undefs/unSDL_shape.h"
		#include "Undefs/unSDL_system.h"
		#include "Undefs/unSDL_timer.h"
		#include "Undefs/unSDL_version.h"
		#include "Undefs/unSDL_video.h"
		
		
		
		#include "Undefs/unSDL_config.h"
		#include "Undefs/unbegin_code.h"
		
	}
	
}

#endif
