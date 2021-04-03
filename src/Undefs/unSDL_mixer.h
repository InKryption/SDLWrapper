
#ifdef SDL_MIXER_VERSION_ATLEAST
	static constexpr auto MIXER_VERSION_ATLEAST(auto X, auto Y, auto Z)
	{
		return SDL_MIXER_VERSION_ATLEAST(X, Y, Z);
		#undef SDL_MIXER_VERSION_ATLEAST
	}
#endif

#ifdef SDL_MIXER_COMPILEDVERSION
	static constexpr auto MIXER_COMPILEDVERSION = SDL_MIXER_COMPILEDVERSION;
	#undef SDL_MIXER_COMPILEDVERSION
#endif

#ifdef SDL_MIXER_VERSION
	static constexpr auto MIXER_VERSION(SDL_version* X)
	{
		SDL_MIXER_VERSION(X);
		#undef SDL_MIXER_VERSION
	}
#endif

#ifdef SDL_MIXER_MAJOR_VERSION
	static constexpr auto MIXER_MAJOR_VERSION = SDL_MIXER_MAJOR_VERSION;
	#undef SDL_MIXER_MAJOR_VERSION
#endif

#ifdef SDL_MIXER_MINOR_VERSION
	static constexpr auto MIXER_MINOR_VERSION = SDL_MIXER_MINOR_VERSION;
	#undef SDL_MIXER_MINOR_VERSION
#endif

#ifdef SDL_MIXER_PATCHLEVEL
	static constexpr auto MIXER_PATCHLEVEL = SDL_MIXER_PATCHLEVEL;
	#undef SDL_MIXER_PATCHLEVEL
#endif

#undef MIX_MAJOR_VERSION
#undef MIX_MINOR_VERSION
#undef MIX_PATCHLEVEL
#undef MIX_VERSION

#ifdef MIX_CHANNELS
	static constexpr auto MIXER_CHANNELS = MIX_CHANNELS;
	#undef MIX_CHANNELS
	static constexpr auto MIX_CHANNELS = MIXER_CHANNELS;
#endif

#ifdef MIX_DEFAULT_FREQUENCY
	static constexpr auto MIXER_DEFAULT_FREQUENCY = MIX_DEFAULT_FREQUENCY;
	#undef MIX_DEFAULT_FREQUENCY
	static constexpr auto MIX_DEFAULT_FREQUENCY = MIXER_DEFAULT_FREQUENCY;
#endif

#ifdef MIX_DEFAULT_FORMAT
	static constexpr auto MIXER_DEFAULT_FORMAT = MIX_DEFAULT_FORMAT;
	#undef MIX_DEFAULT_FORMAT
	static constexpr auto MIX_DEFAULT_FORMAT = MIXER_DEFAULT_FORMAT;
#endif

#ifdef MIX_DEFAULT_CHANNELS
	static constexpr auto MIXER_DEFAULT_CHANNELS = MIX_DEFAULT_CHANNELS;
	#undef MIX_DEFAULT_CHANNELS
	static constexpr auto MIX_DEFAULT_CHANNELS = MIXER_DEFAULT_CHANNELS;
#endif

#ifdef MIX_MAX_VOLUME
	static constexpr auto MIXER_MAX_VOLUME = MIX_MAX_VOLUME;
	#undef MIX_MAX_VOLUME
	static constexpr auto MIX_MAX_VOLUME = MIXER_MAX_VOLUME;
#endif

#ifdef Mix_LoadWAV
	static inline auto Mixer_LoadWAV(const char* file)
	{
		return Mix_LoadWAV(file);
		#undef Mix_LoadWAV
	}
	
	static constexpr auto& Mix_LoadWAV = Mixer_LoadWAV;
#endif

#ifdef MIX_CHANNEL_POST
	static constexpr auto MIXER_CHANNEL_POST = MIX_CHANNEL_POST;
	#undef MIX_CHANNEL_POST
	static constexpr auto MIX_CHANNEL_POST = MIXER_CHANNEL_POST;
#endif

#ifdef MIX_EFFECTSMAXSPEED
	static constexpr auto MIXER_EFFECTSMAXSPEED = MIX_EFFECTSMAXSPEED;
	#undef MIX_EFFECTSMAXSPEED
	static constexpr auto MIX_EFFECTSMAXSPEED = MIXER_EFFECTSMAXSPEED;
#endif

#ifdef Mix_PlayChannel
	static inline auto Mixer_PlayChannel(int channel, Mix_Chunk *chunk, int loops)
	{
		return Mix_PlayChannel(channel, chunk, loops);
		#undef Mix_PlayChannel
	}
	
	static constexpr auto& Mix_PlayChannel = Mixer_PlayChannel;
#endif

#ifdef Mix_FadeInChannel
	static inline auto Mixer_FadeInChannel(int channel, Mix_Chunk *chunk, int loops, int ms)
	{
		return Mix_FadeInChannel(channel, chunk, loops, ms);
		#undef Mix_FadeInChannel
	}
	
	static constexpr auto& Mix_FadeInChannel = Mixer_FadeInChannel;
#endif

#ifdef Mix_SetError
	static constexpr auto Mixer_SetError = Mix_SetError;
	#undef Mix_SetError
	static constexpr auto Mix_SetError = Mixer_SetError;
#endif

#ifdef Mix_GetError
	static constexpr auto Mixer_GetError = Mix_GetError;
	#undef Mix_GetError
	static constexpr auto Mix_GetError = Mixer_GetError;
#endif

#ifdef Mix_ClearError
	static constexpr auto Mixer_ClearError = Mix_ClearError;
	#undef Mix_ClearError
	static constexpr auto Mix_ClearError = Mixer_ClearError;
#endif

