
static constexpr auto MAIN_AVAILABLE =
#if defined(SDL_MAIN_NEEDED)
true
#undef SDL_MAIN_NEEDED
#else
false
#endif
;

static constexpr auto MAIN_NEEDED =
#if defined(SDL_MAIN_NEEDED)
true
#undef SDL_MAIN_NEEDED
#else
false
#endif
;

static constexpr auto MAIN_HANDLED =
#if defined(SDL_MAIN_HANDLED)
true
#undef SDL_MAIN_HANDLED
#else
false
#endif
;

#ifdef SDLMAIN_DECLSPEC
	#define RSTRINGIZE(x) "" #x
	#define STRINGIZE(x) RSTRINGIZE(x)

	static constexpr auto MAIN_DECLSPEC = STRINGIZE(SDLMAIN_DECLSPEC);

	#undef STRINGIZE
	#undef RSTRINGIZE

	#undef SDLMAIN_DECLSPEC
#endif

