#ifdef SDL_LIL_ENDIAN
	static constexpr LIL_ENDIAN = SDL_LIL_ENDIAN;
	#undef SDL_LIL_ENDIAN
#endif

#ifdef SDL_BIG_ENDIAN
	static constexpr BIG_ENDIAN = SDL_BIG_ENDIAN;
	#undef SDL_BIG_ENDIAN
#endif

#ifdef SDL_BYTEORDER
	static constexpr BYTEORDER = SDL_BYTEORDER;
	#undef SDL_BYTEORDER
#endif

#ifdef SDL_SwapLE16
	static constexpr auto SwapLE16(auto X)
	{
		return SDL_SwapLE16(X);
		#undef SDL_SwapLE16
	}
#endif

#ifdef SDL_SwapLE32
	static constexpr auto SwapLE32(auto X)
	{
		return SDL_SwapLE32(X);
		#undef SDL_SwapLE32
	}
#endif

#ifdef SDL_SwapLE64
	static constexpr auto SwapLE64(auto X)
	{
		return SDL_SwapLE64(X);
		#undef SDL_SwapLE64
	}
#endif

#ifdef SDL_SwapFloatLE
	static constexpr auto SwapFloatLE(auto X)
	{
		return SDL_SwapFloatLE(X);
		#undef SDL_SwapFloatLE
	}
#endif

#ifdef SDL_SwapBE16
	static constexpr auto SwapBE16(auto X)
	{
		return SDL_SwapBE16(X);
		#undef SDL_SwapBE16
	}
#endif

#ifdef SDL_SwapBE32
	static constexpr auto SwapBE32(auto X)
	{
		return SDL_SwapBE32(X);
		#undef SDL_SwapBE32
	}
#endif

#ifdef SDL_SwapBE64
	static constexpr auto SwapBE64(auto X)
	{
		return SDL_SwapBE64(X);
		#undef SDL_SwapBE64
	}
#endif

#ifdef SDL_SwapFloatBE
	static constexpr auto SwapFloatBE(auto X)
	{
		return SDL_SwapFloatBE(X);
		#undef SDL_SwapFloatBE
	}
#endif

