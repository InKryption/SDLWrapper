#ifndef INK_SDLWRAPPER_COLOR_STRUCT_WRAPPER_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_COLOR_STRUCT_WRAPPER_HEADER_FILE_GUARD

#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	namespace detail {
		
		template<bool includeAlpha = false> struct RGBA;
		
		template<> struct RGBA<false> {
			constexpr RGBA() {}
			constexpr RGBA(internal::Uint8 r, internal::Uint8 g, internal::Uint8 b): r(r), g(g), b(b) {}
			
			internal::Uint8 r = 0, g = 0, b = 0;
		};
		
		template<> struct RGBA<true>: public RGBA<false> {
			constexpr RGBA() {}
			constexpr RGBA(RGBA<false> const& rgb): RGBA<false>(rgb), a(255) {}
			constexpr RGBA(internal::Uint8 r, internal::Uint8 g, internal::Uint8 b, internal::Uint8 a = 255): RGBA<false>(r, g, b), a(a) {}
			
			constexpr operator internal::SDL_Color()
			{ return internal::SDL_Color{this->r, this->g, this->b, this->a}; }
			
			internal::Uint8 a = 255;
		};
		
	}
	
	
	using RGB = detail::RGBA<false>;
	using RGBA = detail::RGBA<true>;
	
	namespace RGB_Preset {
		
		static constexpr auto
			RED		= RGB(	255,	0,		0	),
			GREEN	= RGB(	0,		255,	0	),
			BLUE	= RGB(	0,		0,		255	),
			
			YELLOW	= RGB(	255,	255,	0	),
			CYAN	= RGB(	0,		255,	255	),
			MAGENTA	= RGB(	255,	0,		255	),
			
			BLACK	= RGB(	0,		0,		0	),
			GREY	= RGB(	127,	127,	127	),
			WHITE	= RGB(	255,	255,	255	)
		;
		
	}
	
}

#endif