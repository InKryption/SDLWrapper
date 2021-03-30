// SDL_stdinc.h

#ifdef SDL_arraysize
	#undef SDL_arraysize
#endif

#ifdef SDL_TABLESIZE
	#undef SDL_TABLESIZE
#endif



#ifdef SDL_STRINGIFY_ARG
	#undef SDL_STRINGIFY_ARG
#endif



#ifdef SDL_FOURCC
	static constexpr auto
	FOURCC(auto A, auto B, auto C, auto D)
	{
		return SDL_FOURCC(A, B, C, D);
		#undef SDL_FOURCC
	}
#endif



#ifdef SDL_reinterpret_cast
	#undef SDL_reinterpret_cast
#endif

#ifdef SDL_static_cast
	#undef SDL_static_cast
#endif

#ifdef SDL_const_cast
	#undef SDL_const_cast
#endif



#ifdef SDL_COMPILE_TIME_ASSERT
	#undef SDL_COMPILE_TIME_ASSERT
#endif



#if defined(SDL_PRIs64)
	#undef SDL_PRIs64
#endif

#if defined(SDL_PRIu64)
	#undef SDL_PRIu64
#endif

#if defined(SDL_PRIx64)
	#undef SDL_PRIx64
#endif

#if defined(SDL_PRIX64)
	#undef SDL_PRIX64
#endif



#if defined(SDL_stack_alloc)
	#undef SDL_stack_alloc
#endif

#if defined(SDL_stack_free)
	#undef SDL_stack_free
#endif



#if defined(SDL_iconv_utf8_locale)
	static inline auto iconv_utf8_locale(const char* S)
	{
		return SDL_iconv_utf8_locale(S);
		#undef SDL_iconv_utf8_locale
	}
#endif

#if defined(SDL_iconv_utf8_ucs2)
	static inline auto iconv_utf8_ucs2(const char* S)
	{
		return SDL_iconv_utf8_ucs2(S);
		#undef SDL_iconv_utf8_ucs2
	}
#endif

#if defined(SDL_iconv_utf8_ucs4)
	static inline auto iconv_utf8_ucs4(const char* S)
	{
		return SDL_iconv_utf8_ucs4(S);
		#undef SDL_iconv_utf8_ucs4
	}
#endif



#if defined(SDL_malloc)
	#undef SDL_malloc
#endif

#if defined(SDL_calloc)
	#undef SDL_calloc
#endif

#if defined(SDL_realloc)
	#undef SDL_realloc
#endif

#if defined(SDL_free)
	#undef SDL_free
#endif

#if defined(SDL_memset)
	#undef SDL_memset
#endif

#if defined(SDL_memcpy)
	#undef SDL_memcpy
#endif

#if defined(SDL_memmove)
	#undef SDL_memmove
#endif

#if defined(SDL_memcmp)
	#undef SDL_memcmp
#endif

#if defined(SDL_strlcpy)
	#undef SDL_strlcpy
#endif

#if defined(SDL_strlcat)
	#undef SDL_strlcat
#endif

#if defined(SDL_strlen)
	#undef SDL_strlen
#endif

#if defined(SDL_wcslen)
	#undef SDL_wcslen
#endif

#if defined(SDL_wcslcpy)
	#undef SDL_wcslcpy
#endif

#if defined(SDL_wcslcat)
	#undef SDL_wcslcat
#endif

#if defined(SDL_strdup)
	#undef SDL_strdup
#endif

#if defined(SDL_wcsdup)
	#undef SDL_wcsdup
#endif

#if defined(SDL_strchr)
	#undef SDL_strchr
#endif

#if defined(SDL_strrchr)
	#undef SDL_strrchr
#endif

#if defined(SDL_strstr)
	#undef SDL_strstr
#endif

#if defined(SDL_wcsstr)
	#undef SDL_wcsstr
#endif

#if defined(SDL_strtokr)
	#undef SDL_strtokr
#endif

#if defined(SDL_strcmp)
	#undef SDL_strcmp
#endif

#if defined(SDL_wcscmp)
	#undef SDL_wcscmp
#endif

#if defined(SDL_strncmp)
	#undef SDL_strncmp
#endif

#if defined(SDL_wcsncmp)
	#undef SDL_wcsncmp
#endif

#if defined(SDL_strcasecmp)
	#undef SDL_strcasecmp
#endif

#if defined(SDL_strncasecmp)
	#undef SDL_strncasecmp
#endif

#if defined(SDL_sscanf)
	#undef SDL_sscanf
#endif

#if defined(SDL_vsscanf)
	#undef SDL_vsscanf
#endif

#if defined(SDL_snprintf)
	#undef SDL_snprintf
#endif

#if defined(SDL_vsnprintf)
	#undef SDL_vsnprintf
#endif

#if defined(SDL_IN_BYTECAP)
	#undef SDL_IN_BYTECAP
#endif

#if defined(SDL_INOUT_Z_CAP)
	#undef SDL_INOUT_Z_CAP
#endif

#if defined(SDL_OUT_Z_CAP)
	#undef SDL_OUT_Z_CAP
#endif

#if defined(SDL_OUT_CAP)
	#undef SDL_OUT_CAP
#endif

#if defined(SDL_OUT_BYTECAP)
	#undef SDL_OUT_BYTECAP
#endif

#if defined(SDL_OUT_Z_BYTECAP)
	#undef SDL_OUT_Z_BYTECAP
#endif

#if defined(SDL_PRINTF_FORMAT_STRING)
	#undef SDL_PRINTF_FORMAT_STRING
#endif

#if defined(SDL_SCANF_FORMAT_STRING)
	#undef SDL_SCANF_FORMAT_STRING
#endif

#if defined(SDL_PRINTF_VARARG_FUNC)
	#undef SDL_PRINTF_VARARG_FUNC
#endif

#if defined(SDL_SCANF_VARARG_FUNC)
	#undef SDL_SCANF_VARARG_FUNC
#endif
