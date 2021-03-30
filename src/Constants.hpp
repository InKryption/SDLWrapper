// SDL_stdinc.h

#if defined(SDL_MAX_SINT8)
	#undef SDL_MAX_SINT8
#endif

#if defined(SDL_MIN_SINT8)
	#undef SDL_MIN_SINT8
#endif

#if defined(SDL_MAX_UINT8)
	#undef SDL_MAX_UINT8
#endif

#if defined(SDL_MIN_UINT8)
	#undef SDL_MIN_UINT8
#endif

#if defined(SDL_MAX_SINT16)
	#undef SDL_MAX_SINT16
#endif

#if defined(SDL_MIN_SINT16)
	#undef SDL_MIN_SINT16
#endif

#if defined(SDL_MAX_UINT16)
	#undef SDL_MAX_UINT16
#endif

#if defined(SDL_MIN_UINT16)
	#undef SDL_MIN_UINT16
#endif

#if defined(SDL_MAX_SINT32)
	#undef SDL_MAX_SINT32
#endif

#if defined(SDL_MIN_SINT32)
	#undef SDL_MIN_SINT32
#endif

#if defined(SDL_MAX_UINT32)
	#undef SDL_MAX_UINT32
#endif

#if defined(SDL_MIN_UINT32)
	#undef SDL_MIN_UINT32
#endif

#if defined(SDL_MAX_SINT64)
	#undef SDL_MAX_SINT64
#endif

#if defined(SDL_MIN_SINT64)
	#undef SDL_MIN_SINT64
#endif

#if defined(SDL_MAX_UINT64)
	#undef SDL_MAX_UINT64
#endif

#if defined(SDL_MIN_UINT64)
	#undef SDL_MIN_UINT64
#endif



#ifdef SDL_TRUE
#undef SDL_TRUE
#endif

#ifdef SDL_FALSE
#undef SDL_FALSE
#endif



#if defined(SDL_ICONV_ERROR)
	static constexpr auto ICONV_ERROR = SDL_ICONV_ERROR;
	#undef SDL_ICONV_ERROR
#endif

#if defined(SDL_ICONV_E2BIG)
	static constexpr auto ICONV_E2BIG = SDL_ICONV_E2BIG;
	#undef SDL_ICONV_E2BIG
#endif

#if defined(SDL_ICONV_EILSEQ)
	static constexpr auto ICONV_EILSEQ = SDL_ICONV_EILSEQ;
	#undef SDL_ICONV_EILSEQ
#endif

#if defined(SDL_ICONV_EINVAL)
	static constexpr auto ICONV_EINVAL = SDL_ICONV_EINVAL;
	#undef SDL_ICONV_EINVAL
#endif

// SDL_audio.h

#if defined(SDL_AUDIO_BITSIZE)
	static constexpr auto AUDIO_BITSIZE(auto x)
	{
		return SDL_AUDIO_BITSIZE(x);
		#undef SDL_AUDIO_BITSIZE
	}
#endif

#if defined(SDL_AUDIO_ISFLOAT)
	static constexpr auto AUDIO_ISFLOAT(auto x)
	{
		return SDL_AUDIO_ISFLOAT(x);
		#undef SDL_AUDIO_ISFLOAT
	}
#endif

#if defined(SDL_AUDIO_ISBIGENDIAN)
	static constexpr auto AUDIO_ISBIGENDIAN(auto x)
	{
		return SDL_AUDIO_ISBIGENDIAN(x);
		#undef SDL_AUDIO_ISBIGENDIAN
	}
#endif

#if defined(SDL_AUDIO_ISSIGNED)
	static constexpr auto AUDIO_ISSIGNED(auto x)
	{
		return SDL_AUDIO_ISSIGNED(x);
		#undef SDL_AUDIO_ISSIGNED
	}
#endif

#if defined(SDL_AUDIO_ISINT)
	static constexpr auto AUDIO_ISINT(auto x)
	{
		return SDL_AUDIO_ISINT(x);
		#undef SDL_AUDIO_ISINT
	}
#endif

#if defined(SDL_AUDIO_ISLITTLEENDIAN)
	static constexpr auto AUDIO_ISLITTLEENDIAN(auto x)
	{
		return SDL_AUDIO_ISLITTLEENDIAN(x);
		#undef SDL_AUDIO_ISLITTLEENDIAN
	}
#endif

#if defined(SDL_AUDIO_ISUNSIGNED)
	static constexpr auto AUDIO_ISUNSIGNED(auto x)
	{
		return SDL_AUDIO_ISUNSIGNED(x);
		#undef SDL_AUDIO_ISUNSIGNED
	}
#endif



#if defined(SDL_AUDIO_MASK_BITSIZE)
	static constexpr auto AUDIO_MASK_BITSIZE = SDL_AUDIO_MASK_BITSIZE;
	#undef SDL_AUDIO_MASK_BITSIZE
#endif

#if defined(SDL_AUDIO_MASK_DATATYPE)
	static constexpr auto AUDIO_MASK_DATATYPE = SDL_AUDIO_MASK_DATATYPE;
	#undef SDL_AUDIO_MASK_DATATYPE
#endif

#if defined(SDL_AUDIO_MASK_ENDIAN)
	static constexpr auto AUDIO_MASK_ENDIAN = SDL_AUDIO_MASK_ENDIAN;
	#undef SDL_AUDIO_MASK_ENDIAN
#endif

#if defined(SDL_AUDIO_MASK_SIGNED)
	static constexpr auto AUDIO_MASK_SIGNED = SDL_AUDIO_MASK_SIGNED;
	#undef SDL_AUDIO_MASK_SIGNED
#endif



#if defined(SDL_AUDIO_ALLOW_ANY_CHANGE)
	static constexpr auto AUDIO_ALLOW_ANY_CHANGE = SDL_AUDIO_ALLOW_ANY_CHANGE;
	#undef SDL_AUDIO_ALLOW_ANY_CHANGE
#endif

#if defined(SDL_AUDIO_ALLOW_SAMPLES_CHANGE)
	static constexpr auto AUDIO_ALLOW_SAMPLES_CHANGE = SDL_AUDIO_ALLOW_SAMPLES_CHANGE;
	#undef SDL_AUDIO_ALLOW_SAMPLES_CHANGE
#endif

#if defined(SDL_AUDIO_ALLOW_CHANNELS_CHANGE)
	static constexpr auto AUDIO_ALLOW_CHANNELS_CHANGE = SDL_AUDIO_ALLOW_CHANNELS_CHANGE;
	#undef SDL_AUDIO_ALLOW_CHANNELS_CHANGE
#endif

#if defined(SDL_AUDIO_ALLOW_FORMAT_CHANGE)
	static constexpr auto AUDIO_ALLOW_FORMAT_CHANGE = SDL_AUDIO_ALLOW_FORMAT_CHANGE;
	#undef SDL_AUDIO_ALLOW_FORMAT_CHANGE
#endif

#if defined(SDL_AUDIO_ALLOW_FREQUENCY_CHANGE)
	static constexpr auto AUDIO_ALLOW_FREQUENCY_CHANGE = SDL_AUDIO_ALLOW_FREQUENCY_CHANGE;
	#undef SDL_AUDIO_ALLOW_FREQUENCY_CHANGE
#endif
