#ifdef SDL_TICKS_PASSED
	static constexpr auto TICKS_PASSED(auto A, auto B)
	{
		return SDL_TICKS_PASSED(A, B);
		#undef SDL_TICKS_PASSED
	}
#endif

