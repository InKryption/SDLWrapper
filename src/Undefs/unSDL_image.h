#ifdef SDL_IMAGE_VERSION_ATLEAST
	static constexpr auto IMAGE_VERSION_ATLEAST(auto X, auto Y, auto Z)
	{
		SDL_IMAGE_VERSION_ATLEAST(X, Y, Z);
		#undef SDL_IMAGE_VERSION_ATLEAST
	}
#endif

#ifdef SDL_IMAGE_COMPILEDVERSION
	static constexpr auto IMAGE_COMPILEDVERSION = SDL_IMAGE_COMPILEDVERSION;
	#undef SDL_IMAGE_COMPILEDVERSION
#endif

#ifdef SDL_IMAGE_VERSION
	static constexpr auto IMAGE_VERSION(SDL_version* v)
	{
		SDL_IMAGE_VERSION(v);
		#undef SDL_IMAGE_VERSION
	}
#endif

#ifdef SDL_IMAGE_MAJOR_VERSION
	static constexpr auto IMAGE_MAJOR_VERSION = SDL_IMAGE_MAJOR_VERSION;
	#undef SDL_IMAGE_MAJOR_VERSION
#endif

#ifdef SDL_IMAGE_MINOR_VERSION
	static constexpr auto IMAGE_MINOR_VERSION = SDL_IMAGE_MINOR_VERSION;
	#undef SDL_IMAGE_MINOR_VERSION
#endif

#ifdef SDL_IMAGE_PATCHLEVEL
	static constexpr auto IMAGE_PATCHLEVEL = SDL_IMAGE_PATCHLEVEL;
	#undef SDL_IMAGE_PATCHLEVEL
#endif

#ifdef IMG_SetError
	static constexpr auto IMAGE_SetError = IMG_SetError;
	#undef IMG_SetError
	static constexpr auto IMG_SetError = IMAGE_SetError;
#endif

#ifdef IMG_GetError
	static constexpr auto IMAGE_GetError = IMG_GetError;
	#undef IMG_GetError
	static constexpr auto IMG_GetError = IMAGE_GetError;
#endif

