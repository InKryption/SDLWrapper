#ifndef INK_SDLWRAPPER_MAIN_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_MAIN_HEADER_FILE_GUARD

#include <cstdlib>

namespace ink::SDL {
	
	namespace internal {
		
		#if !defined(__CC_ARM)
			#define INK_CC_ARM_DECEIT
			#define __CC_ARM
		#endif
		
		#define SDL_assert_h_
		#define SDL_atomic_h_
		#define SDL_filesystem_h_
		#define SDL_log_h_
		#include <SDL2/SDL.h>
		#undef SDL_log_h_
		#undef SDL_filesystem_h_
		#undef SDL_atomic_h_
		#undef SDL_assert_h_
		
		#if defined(INK_CC_ARM_DECEIT)
			#undef __CC_ARM
			#undef INK_CC_ARM_DECEIT
		#endif
		
		#ifdef SDL_TRUE
			#undef SDL_TRUE
		#endif
		
		#ifdef SDL_FALSE
			#undef SDL_FALSE
		#endif
		
		#ifdef SDL_AUDIOCVT_PACKED
			#undef SDL_AUDIOCVT_PACKED
		#endif
		
		#ifdef DECLSPEC
			#undef DECLSPEC
		#endif
		
		#include "Constants.hpp"
		#include "Macros.hpp"
		
	}
	
}

#endif
