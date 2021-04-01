#ifndef INK_SDLWRAPPER_MAIN_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_MAIN_HEADER_FILE_GUARD

#include <cstdlib>

namespace ink::SDL {
	
	namespace internal {
		
		
		#define SDL_atomic_h_ // Duplicates the standard library. Also, too lazy to actually go through the trouble of cleaning up the macros
		
		#include <SDL2/SDL.h>
		
		#include "Undefs/unSDL.h"
		#include "Undefs/unSDL_main.h"
		#include "Undefs/unSDL_stdinc.h"
		#include "Undefs/unSDL_assert.h"
		#include "Undefs/unSDL_audio.h"
		#include "Undefs/unSDL_cpuinfo.h"
		#include "Undefs/unSDL_endian.h"
		#include "Undefs/unSDL_error.h"
		#include "Undefs/unSDL_events.h"
		
	}
	
}

#endif
