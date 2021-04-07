
#define rStringize(x) #x
#define Stringize(x) rStringize(x)

#ifdef SDLCALL
	static constexpr auto CALL = Stringize(SDLCALL);
	#undef SDLCALL
#endif

#ifdef DECLSPEC
	static constexpr auto DECLSPEC_STR = Stringize(DECLSPEC);
	#undef DECLSPEC
	static constexpr auto DECLSPEC = DECLSPEC_STR;
#endif

#ifdef SDL_INLINE
	static constexpr auto INLINE = Stringize(SDL_INLINE);
	#undef SDL_INLINE
#endif

#ifdef SDL_FORCE_INLINE
	static constexpr auto FORCE_INLINE = Stringize(SDL_FORCE_INLINE);
	#undef SDL_FORCE_INLINE
#endif

#ifdef SDL_NORETURN
	static constexpr auto NORETURN = Stringize(SDL_NORETURN);
	#undef SDL_NORETURN
#endif

#ifdef SDL_DEPRECATED
	static constexpr auto DEPRECATED = Stringize(SDL_DEPRECATED);
	#undef SDL_DEPRECATED
#endif

#ifdef SDL_UNUSED
	static constexpr auto UNUSED = Stringize(SDL_UNUSED);
	#undef SDL_UNUSED
#endif

#undef Stringize
#undef rStringize
