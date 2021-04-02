#ifdef SDL_RWOPS_UNKNOWN
	static constexpr auto RWOPS_UNKNOWN = SDL_RWOPS_UNKNOWN;
	#undef SDL_RWOPS_UNKNOWN
#endif

#ifdef SDL_RWOPS_WINFILE
	static constexpr auto RWOPS_WINFILE = SDL_RWOPS_WINFILE;
	#undef SDL_RWOPS_WINFILE
#endif

#ifdef SDL_RWOPS_STDFILE
	static constexpr auto RWOPS_STDFILE = SDL_RWOPS_STDFILE;
	#undef SDL_RWOPS_STDFILE
#endif

#ifdef SDL_RWOPS_JNIFILE
	static constexpr auto RWOPS_JNIFILE = SDL_RWOPS_JNIFILE;
	#undef SDL_RWOPS_JNIFILE
#endif

#ifdef SDL_RWOPS_MEMORY
	static constexpr auto RWOPS_MEMORY = SDL_RWOPS_MEMORY;
	#undef SDL_RWOPS_MEMORY
#endif

#ifdef SDL_RWOPS_MEMORY_RO
	static constexpr auto RWOPS_MEMORY_RO = SDL_RWOPS_MEMORY_RO;
	#undef SDL_RWOPS_MEMORY_RO
#endif

#ifdef RW_SEEK_SET
	static constexpr auto RWOPS_SEEK_SET = RW_SEEK_SET;
	#undef RW_SEEK_SET
	static constexpr auto RW_SEEK_SET = RWOPS_SEEK_SET;
#endif

#ifdef RW_SEEK_CUR
	static constexpr auto RWOPS_SEEK_CUR = RW_SEEK_CUR;
	#undef RW_SEEK_CUR
	static constexpr auto RW_SEEK_CUR = RWOPS_SEEK_CUR;
#endif

#ifdef RW_SEEK_END
	static constexpr auto RWOPS_SEEK_END = RW_SEEK_END;
	#undef RW_SEEK_END
	static constexpr auto RW_SEEK_END = RWOPS_SEEK_END;
#endif
