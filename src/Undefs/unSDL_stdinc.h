
// As far as I tested them, these macros (SDL_arraysize and SDL_TABLESIZE) wouldn't work as intended, and I couldn't find any documentation for them.
#undef SDL_arraysize
#undef SDL_TABLESIZE

// Everyone abd their mother can do this
#undef SDL_STRINGIFY_ARG

#ifdef SDL_FOURCC
	// (Macro wrapper) Define a four character code as a Uint32
	static constexpr auto FOURCC(auto A, auto B, auto C, auto D)
	{
		return SDL_FOURCC(A, B, C, D);
		#undef SDL_FOURCC
	}
#endif

// Since this is a wrapper for C++, there is no point to making C-compatability layers for the casts
#undef SDL_reinterpret_cast
#undef SDL_static_cast
#undef SDL_const_cast

// true & false
#undef SDL_TRUE
#undef SDL_FALSE

// We have numeric_limits in C++. But I'll redefine them just in case.

#ifdef SDL_MAX_SINT8
	static constexpr auto MAX_SINT8 = SDL_MAX_SINT8;
	#undef SDL_MAX_SINT8
#endif

#ifdef SDL_MIN_SINT8
	static constexpr auto MIN_SINT8 = SDL_MIN_SINT8;
	#undef SDL_MIN_SINT8
#endif

#ifdef SDL_MAX_UINT8
	static constexpr auto MAX_UINT8 = SDL_MAX_UINT8;
	#undef SDL_MAX_UINT8
#endif

#ifdef SDL_MIN_UINT8
	static constexpr auto MIN_UINT8 = SDL_MIN_UINT8;
	#undef SDL_MIN_UINT8
#endif

#ifdef SDL_MAX_SINT16
	static constexpr auto MAX_SINT16 = SDL_MAX_SINT16;
	#undef SDL_MAX_SINT16
#endif

#ifdef SDL_MIN_SINT16
	static constexpr auto MIN_SINT16 = SDL_MIN_SINT16;
	#undef SDL_MIN_SINT16
#endif

#ifdef SDL_MAX_UINT16
	static constexpr auto MAX_UINT16 = SDL_MAX_UINT16;
	#undef SDL_MAX_UINT16
#endif

#ifdef SDL_MIN_UINT16
	static constexpr auto MIN_UINT16 = SDL_MIN_UINT16;
	#undef SDL_MIN_UINT16
#endif

#ifdef SDL_MAX_SINT32
	static constexpr auto MAX_SINT32 = SDL_MAX_SINT32;
	#undef SDL_MAX_SINT32
#endif

#ifdef SDL_MIN_SINT32
	static constexpr auto MIN_SINT32 = SDL_MIN_SINT32;
	#undef SDL_MIN_SINT32
#endif

#ifdef SDL_MAX_UINT32
	static constexpr auto MAX_UINT32 = SDL_MAX_UINT32;
	#undef SDL_MAX_UINT32
#endif

#ifdef SDL_MIN_UINT32
	static constexpr auto MIN_UINT32 = SDL_MIN_UINT32;
	#undef SDL_MIN_UINT32
#endif

#ifdef SDL_MAX_SINT64
	static constexpr auto MAX_SINT64 = SDL_MAX_SINT64;
	#undef SDL_MAX_SINT64
#endif

#ifdef SDL_MIN_SINT64
	static constexpr auto MIN_SINT64 = SDL_MIN_SINT64;
	#undef SDL_MIN_SINT64
#endif

#ifdef SDL_MAX_UINT64
	static constexpr auto MAX_UINT64 = SDL_MAX_UINT64;
	#undef SDL_MAX_UINT64
#endif

#ifdef SDL_MIN_UINT64
	static constexpr auto MIN_UINT64 = SDL_MIN_UINT64;
	#undef SDL_MIN_UINT64
#endif


#undef SDL_PRIs64
#undef SDL_PRIu64
#undef SDL_PRIx64
#undef SDL_PRIX64

static constexpr auto DISABLE_ANALYZE_MACROS =
#ifdef SDL_DISABLE_ANALYZE_MACROS
	true
	#undef SDL_DISABLE_ANALYZE_MACROS
#else
	false
#endif
;

#undef SDL_IN_BYTECAP
#undef SDL_INOUT_Z_CAP
#undef SDL_OUT_Z_CAP
#undef SDL_OUT_CAP
#undef SDL_OUT_BYTECAP
#undef SDL_OUT_Z_BYTECAP
#undef SDL_PRINTF_FORMAT_STRING
#undef SDL_SCANF_FORMAT_STRING
#undef SDL_PRINTF_VARARG_FUNC
#undef SDL_SCANF_VARARG_FUNC

#undef SDL_COMPILE_TIME_ASSERT

#undef SDL_stack_alloc
#undef SDL_stack_free

#undef SDL_min
#undef SDL_max

#undef SDL_zero
#undef SDL_zerop
#undef SDL_zeroa



#ifdef SDL_ICONV_ERROR
	static constexpr auto ICONV_ERROR = SDL_ICONV_ERROR;
	#undef SDL_ICONV_ERROR
#endif

#ifdef SDL_ICONV_E2BIG
	static constexpr auto ICONV_E2BIG = SDL_ICONV_E2BIG;
	#undef SDL_ICONV_E2BIG
#endif

#ifdef SDL_ICONV_EILSEQ
	static constexpr auto ICONV_EILSEQ = SDL_ICONV_EILSEQ;
	#undef SDL_ICONV_EILSEQ
#endif

#ifdef SDL_ICONV_EINVAL
	static constexpr auto ICONV_EINVAL = SDL_ICONV_EINVAL;
	#undef SDL_ICONV_EINVAL
#endif



#ifdef SDL_iconv_utf8_locale
	static inline auto iconv_utf8_locale(const char* S)
	{
		return SDL_iconv_utf8_locale(S);
		#undef SDL_iconv_utf8_locale
	}
#endif

#ifdef SDL_iconv_utf8_ucs2
	static inline auto iconv_utf8_ucs2(const char* S)
	{
		return SDL_iconv_utf8_ucs2(S);
		#undef SDL_iconv_utf8_ucs2
	}
#endif

#ifdef SDL_iconv_utf8_ucs4
	static inline auto iconv_utf8_ucs4(const char* S)
	{
		return SDL_iconv_utf8_ucs4(S);
		#undef SDL_iconv_utf8_ucs4
	}
#endif



#undef SDL_malloc
#undef SDL_calloc
#undef SDL_realloc
#undef SDL_free
#undef SDL_memset
#undef SDL_memcpy
#undef SDL_memmove
#undef SDL_memcmp
#undef SDL_strlcpy
#undef SDL_strlcat
#undef SDL_strlen
#undef SDL_wcslen
#undef SDL_wcslcpy
#undef SDL_wcslcat
#undef SDL_strdup
#undef SDL_wcsdup
#undef SDL_strchr
#undef SDL_strrchr
#undef SDL_strstr
#undef SDL_wcsstr
#undef SDL_strtokr
#undef SDL_strcmp
#undef SDL_wcscmp
#undef SDL_strncmp
#undef SDL_wcsncmp
#undef SDL_strcasecmp
#undef SDL_strncasecmp
#undef SDL_sscanf
#undef SDL_vsscanf
#undef SDL_snprintf
#undef SDL_vsnprintf
