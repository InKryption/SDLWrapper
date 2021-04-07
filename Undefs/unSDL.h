

#ifdef SDL_INIT_EVERYTHING
	static constexpr auto INIT_EVERYTHING = SDL_INIT_EVERYTHING;
	#undef SDL_INIT_EVERYTHING
#endif

#ifdef SDL_INIT_NOPARACHUTE
	static constexpr auto INIT_NOPARACHUTE = SDL_INIT_NOPARACHUTE;
	#undef SDL_INIT_NOPARACHUTE
#endif

#ifdef SDL_INIT_SENSOR
	static constexpr auto INIT_SENSOR = SDL_INIT_SENSOR;
	#undef SDL_INIT_SENSOR
#endif

#ifdef SDL_INIT_EVENTS
	static constexpr auto INIT_EVENTS = SDL_INIT_EVENTS;
	#undef SDL_INIT_EVENTS
#endif

#ifdef SDL_INIT_GAMECONTROLLER
	static constexpr auto INIT_GAMECONTROLLER = SDL_INIT_GAMECONTROLLER;
	#undef SDL_INIT_GAMECONTROLLER
#endif

#ifdef SDL_INIT_HAPTIC
	static constexpr auto INIT_HAPTIC = SDL_INIT_HAPTIC;
	#undef SDL_INIT_HAPTIC
#endif

#ifdef SDL_INIT_JOYSTICK
	static constexpr auto INIT_JOYSTICK = SDL_INIT_JOYSTICK;
	#undef SDL_INIT_JOYSTICK
#endif

#ifdef SDL_INIT_VIDEO
	static constexpr auto INIT_VIDEO = SDL_INIT_VIDEO;
	#undef SDL_INIT_VIDEO
#endif

#ifdef SDL_INIT_AUDIO
	static constexpr auto INIT_AUDIO = SDL_INIT_AUDIO;
	#undef SDL_INIT_AUDIO
#endif

#ifdef SDL_INIT_TIMER
	static constexpr auto INIT_TIMER = SDL_INIT_TIMER;
	#undef SDL_INIT_TIMER
#endif
