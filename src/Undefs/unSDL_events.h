#ifdef SDL_RELEASED
	static constexpr auto RELEASED = SDL_RELEASED;
	#undef SDL_RELEASED
#endif

#ifdef SDL_PRESSED
	static constexpr auto PRESSED = SDL_PRESSED;
	#undef SDL_PRESSED
#endif

#ifdef SDL_TEXTEDITINGEVENT_TEXT_SIZE
	static constexpr auto TEXTEDITINGEVENT_TEXT_SIZE = SDL_TEXTEDITINGEVENT_TEXT_SIZE;
	#undef SDL_TEXTEDITINGEVENT_TEXT_SIZE
#endif

#ifdef SDL_TEXTINPUTEVENT_TEXT_SIZE
	static constexpr auto TEXTINPUTEVENT_TEXT_SIZE = SDL_TEXTINPUTEVENT_TEXT_SIZE;
	#undef SDL_TEXTINPUTEVENT_TEXT_SIZE
#endif

#ifdef SDL_QUERY
	static constexpr auto QUERY = SDL_QUERY;
	#undef SDL_QUERY
#endif

#ifdef SDL_IGNORE
	static constexpr auto IGNORE = SDL_IGNORE;
	#undef SDL_IGNORE
#endif

#ifdef SDL_DISABLE
	static constexpr auto DISABLE = SDL_DISABLE;
	#undef SDL_DISABLE
#endif

#ifdef SDL_ENABLE
	static constexpr auto ENABLE = SDL_ENABLE;
	#undef SDL_ENABLE
#endif

#ifdef SDL_GetEventState
	static inline auto GetEventState(Uint32 type)
	{
		return SDL_GetEventState(type);
		#undef SDL_GetEventState
	}
#endif

