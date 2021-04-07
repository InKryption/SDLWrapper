#ifdef SDL_NONSHAPEABLE_WINDOW
	static constexpr auto NONSHAPEABLE_WINDOW = SDL_NONSHAPEABLE_WINDOW;
	#undef SDL_NONSHAPEABLE_WINDOW
#endif

#ifdef SDL_INVALID_SHAPE_ARGUMENT
	static constexpr auto INVALID_SHAPE_ARGUMENT = SDL_INVALID_SHAPE_ARGUMENT;
	#undef SDL_INVALID_SHAPE_ARGUMENT
#endif

#ifdef SDL_WINDOW_LACKS_SHAPE
	static constexpr auto WINDOW_LACKS_SHAPE = SDL_WINDOW_LACKS_SHAPE;
	#undef SDL_WINDOW_LACKS_SHAPE
#endif

#ifdef SDL_SHAPEMODEALPHA
	static constexpr auto SHAPEMODEALPHA(auto mode)
	{
		return SDL_SHAPEMODEALPHA(mode);
		#undef SDL_SHAPEMODEALPHA
	}
#endif