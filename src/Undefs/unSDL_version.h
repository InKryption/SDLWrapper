#ifdef SDL_VERSION
	static constexpr auto VERSION(SDL_version* x)
	{
		SDL_VERSION(x);
		#undef SDL_VERSION
	}
#endif



#ifdef SDL_VERSION_ATLEAST
	static constexpr auto VERSION_ATLEAST(auto X, auto Y, auto Z)
	{
		return SDL_VERSION_ATLEAST(X, Y, Z);
		#undef SDL_VERSION_ATLEAST
	}
#endif

#ifdef SDL_COMPILEDVERSION
	static constexpr auto COMPILEDVERSION = SDL_COMPILEDVERSION;
	#undef SDL_COMPILEDVERSION
#endif

#ifdef SDL_VERSIONNUM
	static constexpr auto VERSIONNUM(auto X, auto Y, auto Z)
	{
		return SDL_VERSIONNUM(X, Y, Z);
		#undef SDL_VERSIONNUM
	}
#endif



#ifdef SDL_MAJOR_VERSION
	static constexpr auto MAJOR_VERSION = SDL_MAJOR_VERSION;
	#undef SDL_MAJOR_VERSION
#endif

#ifdef SDL_MINOR_VERSION
	static constexpr auto MINOR_VERSION = SDL_MINOR_VERSION;
	#undef SDL_MINOR_VERSION
#endif

#ifdef SDL_PATCHLEVEL
	static constexpr auto PATCHLEVEL = SDL_PATCHLEVEL;
	#undef SDL_PATCHLEVEL
#endif
