
#ifdef SDL_MIXER_VERSION_ATLEAST
	static constexpr auto VERSION_ATLEAST(auto X, auto Y, auto Z)
	{
		return SDL_MIXER_VERSION_ATLEAST(X, Y, Z);
		#undef SDL_MIXER_VERSION_ATLEAST
	}
#endif

#ifdef SDL_MIXER_COMPILEDVERSION
	static constexpr auto COMPILEDVERSION = SDL_MIXER_COMPILEDVERSION;
	#undef SDL_MIXER_COMPILEDVERSION
#endif

#ifdef SDL_MIXER_VERSION
	static constexpr auto VERSION(SDL_version* X)
	{
		SDL_MIXER_VERSION(X);
		#undef SDL_MIXER_VERSION
	}
#endif

#ifdef SDL_MIXER_MAJOR_VERSION
	static constexpr auto MAJOR_VERSION = SDL_MIXER_MAJOR_VERSION;
	#undef SDL_MIXER_MAJOR_VERSION
#endif

#ifdef SDL_MIXER_MINOR_VERSION
	static constexpr auto MINOR_VERSION = SDL_MIXER_MINOR_VERSION;
	#undef SDL_MIXER_MINOR_VERSION
#endif

#ifdef SDL_MIXER_PATCHLEVEL
	static constexpr auto PATCHLEVEL = SDL_MIXER_PATCHLEVEL;
	#undef SDL_MIXER_PATCHLEVEL
#endif

#undef MIX_MAJOR_VERSION
#undef MIX_MINOR_VERSION
#undef MIX_PATCHLEVEL
#undef MIX_VERSION

#ifdef MIX_CHANNELS
	static constexpr auto CHANNELS = MIX_CHANNELS;
	#undef MIX_CHANNELS
#endif

#ifdef MIX_DEFAULT_FREQUENCY
	static constexpr auto DEFAULT_FREQUENCY = MIX_DEFAULT_FREQUENCY;
	#undef MIX_DEFAULT_FREQUENCY
#endif

#ifdef MIX_DEFAULT_FORMAT
	static constexpr auto DEFAULT_FORMAT = MIX_DEFAULT_FORMAT;
	#undef MIX_DEFAULT_FORMAT
#endif

#ifdef MIX_DEFAULT_CHANNELS
	static constexpr auto DEFAULT_CHANNELS = MIX_DEFAULT_CHANNELS;
	#undef MIX_DEFAULT_CHANNELS
#endif

#ifdef MIX_MAX_VOLUME
	static constexpr auto MAX_VOLUME = MIX_MAX_VOLUME;
	#undef MIX_MAX_VOLUME
#endif

#ifdef Mix_LoadWAV
	static auto inline LoadWAV(const char* file)
	{
		return Mix_LoadWAV(file);
		#undef Mix_LoadWAV
	}
#endif

#ifdef MIX_CHANNEL_POST
	static constexpr auto CHANNEL_POST = MIX_CHANNEL_POST;
	#undef MIX_CHANNEL_POST
#endif

#ifdef MIX_EFFECTSMAXSPEED
	static constexpr auto EFFECTSMAXSPEED = MIX_EFFECTSMAXSPEED;
	#undef MIX_EFFECTSMAXSPEED
#endif

#ifdef Mix_PlayChannel
	static inline auto PlayChannel(int channel, Mix_Chunk *chunk, int loops)
	{
		return Mix_PlayChannel(channel, chunk, loops);
		#undef Mix_PlayChannel
	}
#endif

#ifdef Mix_FadeInChannel
	static inline auto FadeInChannel(int channel, Mix_Chunk *chunk, int loops, int ms)
	{
		return Mix_FadeInChannel(channel, chunk, loops, ms);
		#undef Mix_FadeInChannel
	}
#endif



#ifdef Mix_SetError
	static constexpr auto SetError = Mix_SetError;
#endif

#ifdef Mix_GetError
	static constexpr auto GetError = Mix_GetError;
#endif

#ifdef Mix_ClearError
	static constexpr auto ClearError = Mix_ClearError;
#endif
