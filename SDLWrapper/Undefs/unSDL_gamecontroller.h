#ifdef SDL_GameControllerAddMappingsFromFile
	static inline auto GameControllerAddMappingsFromFile(const char* file)
	{
		return SDL_GameControllerAddMappingsFromFile(file);
		#undef SDL_GameControllerAddMappingsFromFile
	}
#endif
