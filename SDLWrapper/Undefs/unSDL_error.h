#ifdef SDL_OutOfMemory
	static inline auto OutOfMemory()
	{
		return SDL_OutOfMemory();
		#undef SDL_OutOfMemory
	}
#endif

#ifdef SDL_Unsupported
	static inline auto Unsupported()
	{
		return SDL_Unsupported();
		#undef SDL_Unsupported
	}
#endif

#ifdef SDL_InvalidParamError
	static inline auto InvalidParamError(const char* param)
	{
		return SDL_InvalidParamError(param);
		#undef SDL_InvalidParamError
	}
#endif

