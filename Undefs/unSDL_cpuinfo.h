#ifdef SDL_CACHELINE_SIZE
	static constexpr auto CACHELINE_SIZE = SDL_CACHELINE_SIZE;
	#undef SDL_CACHELINE_SIZE
#endif
