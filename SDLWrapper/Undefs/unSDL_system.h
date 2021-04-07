#ifdef SDL_iOSSetAnimationCallback
	static inline auto iOSSetAnimationCallback(SDL_Window *window, int interval, void (*callback)(void *), void *callbackParam)
	{
		return SDL_iOSSetAnimationCallback(window, interval, callback, callbackParam);
		#undef SDL_iOSSetAnimationCallback
	}
#endif

#ifdef SDL_iOSSetEventPump
	static inline auto iOSSetEventPump(SDL_bool enabled)
	{
		return SDL_iOSSetEventPump(enabled);
		#undef SDL_iOSSetEventPump
	}
#endif

#ifdef SDL_ANDROID_EXTERNAL_STORAGE_READ
	static constexpr auto ANDROID_EXTERNAL_STORAGE_READ = SDL_ANDROID_EXTERNAL_STORAGE_READ;
	#undef SDL_ANDROID_EXTERNAL_STORAGE_READ
#endif

#ifdef SDL_ANDROID_EXTERNAL_STORAGE_WRITE
	static constexpr auto ANDROID_EXTERNAL_STORAGE_WRITE = SDL_ANDROID_EXTERNAL_STORAGE_WRITE;
	#undef SDL_ANDROID_EXTERNAL_STORAGE_WRITE
#endif
