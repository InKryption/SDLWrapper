#ifdef SDL_TTF_VERSION_ATLEAST
	static constexpr auto VERSION_ATLEAST(auto X, auto Y, auto Z)
	{
		return SDL_TTF_VERSION_ATLEAST(X, Y, Z);
		#undef SDL_TTF_VERSION_ATLEAST
	}
#endif

#ifdef SDL_TTF_COMPILEDVERSION
	static constexpr auto COMPILEDVERSION = SDL_TTF_COMPILEDVERSION;
	#undef SDL_TTF_COMPILEDVERSION
#endif

#ifdef SDL_TTF_VERSION
	static constexpr auto VERSION(SDL_version* v)
	{
		SDL_TTF_VERSION(v);
		#undef SDL_TTF_VERSION
	}
#endif

#undef TTF_MAJOR_VERSION
#undef TTF_MINOR_VERSION
#undef TTF_PATCHLEVEL
#undef TTF_VERSION

#ifdef SDL_TTF_MAJOR_VERSION
	static constexpr auto MAJOR_VERSION = SDL_TTF_MAJOR_VERSION;
	#undef SDL_TTF_MAJOR_VERSION
#endif

#ifdef SDL_TTF_MINOR_VERSION
	static constexpr auto MINOR_VERSION = SDL_TTF_MINOR_VERSION;
	#undef SDL_TTF_MINOR_VERSION
#endif

#ifdef SDL_TTF_PATCHLEVEL
	static constexpr auto PATCHLEVEL = SDL_TTF_PATCHLEVEL;
	#undef SDL_TTF_PATCHLEVEL
#endif


#ifdef UNICODE_BOM_NATIVE
	static constexpr auto UNICODE_BOM_NATIV = UNICODE_BOM_NATIVE;
	#undef UNICODE_BOM_NATIVE
	static constexpr auto UNICODE_BOM_NATIVE = UNICODE_BOM_NATIV;
#endif

#ifdef UNICODE_BOM_SWAPPED
	static constexpr auto UNICODE_BOM_SWAPPE = UNICODE_BOM_SWAPPED;
	#undef UNICODE_BOM_SWAPPED
	static constexpr auto UNICODE_BOM_SWAPPED = UNICODE_BOM_SWAPPE;
#endif


#ifdef TTF_STYLE_NORMAL
	static constexpr auto STYLE_NORMAL = TTF_STYLE_NORMAL;
	#undef TTF_STYLE_NORMAL
#endif

#ifdef TTF_STYLE_BOLD
	static constexpr auto STYLE_BOLD = TTF_STYLE_BOLD;
	#undef TTF_STYLE_BOLD
#endif

#ifdef TTF_STYLE_ITALIC
	static constexpr auto STYLE_ITALIC = TTF_STYLE_ITALIC;
	#undef TTF_STYLE_ITALIC
#endif

#ifdef TTF_STYLE_UNDERLINE
	static constexpr auto STYLE_UNDERLINE = TTF_STYLE_UNDERLINE;
	#undef TTF_STYLE_UNDERLINE
#endif

#ifdef TTF_STYLE_STRIKETHROUGH
	static constexpr auto STYLE_STRIKETHROUGH = TTF_STYLE_STRIKETHROUGH;
	#undef TTF_STYLE_STRIKETHROUGH
#endif



#ifdef TTF_HINTING_NORMAL
	static constexpr auto HINTING_NORMAL = TTF_HINTING_NORMAL;
	#undef TTF_HINTING_NORMAL
#endif

#ifdef TTF_HINTING_LIGHT
	static constexpr auto HINTING_LIGHT = TTF_HINTING_LIGHT;
	#undef TTF_HINTING_LIGHT
#endif

#ifdef TTF_HINTING_MONO
	static constexpr auto HINTING_MONO = TTF_HINTING_MONO;
	#undef TTF_HINTING_MONO
#endif

#ifdef TTF_HINTING_NONE
	static constexpr auto HINTING_NONE = TTF_HINTING_NONE;
	#undef TTF_HINTING_NONE
#endif



#ifdef TTF_RenderText
	static inline auto RenderText(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg)
	{
		return TTF_RenderText(font, text, fg, bg);
		#undef TTF_RenderText
	}
#endif

#ifdef TTF_RenderUTF8
	static inline auto RenderUTF8(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg)
	{
		return TTF_RenderUTF8(font, text, fg, bg);
		#undef TTF_RenderUTF8
	}
#endif

#ifdef TTF_RenderUNICODE
	static inline auto RenderUNICODE(TTF_Font *font, const Uint16 *text, SDL_Color fg, SDL_Color bg)
	{
		return TTF_RenderUNICODE(font, text, fg, bg);
		#undef TTF_RenderUNICODE
	}
#endif



#ifdef TTF_SetError
	static constexpr auto SetError = TTF_SetError;
	#undef TTF_SetError
#endif

#ifdef TTF_GetError
	static constexpr auto GetError = TTF_GetError;
	#undef TTF_GetError
#endif

