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

// Audio Flags
namespace AUDIO {
	#ifdef AUDIO_F32SYS
		static constexpr auto F32SYS = AUDIO_F32SYS;
		#undef AUDIO_F32SYS
	#endif
	#ifdef AUDIO_S32SYS
		static constexpr auto S32SYS = AUDIO_S32SYS;
		#undef AUDIO_S32SYS
	#endif
	#ifdef AUDIO_S16SYS
		static constexpr auto S16SYS = AUDIO_S16SYS;
		#undef AUDIO_S16SYS
	#endif
	#ifdef AUDIO_U16SYS
		static constexpr auto U16SYS = AUDIO_U16SYS;
		#undef AUDIO_U16SYS
	#endif
	#ifdef AUDIO_F32
		static constexpr auto F32 = AUDIO_F32;
		#undef AUDIO_F32
	#endif
	#ifdef AUDIO_F32MSB
		static constexpr auto F32MSB = AUDIO_F32MSB;
		#undef AUDIO_F32MSB
	#endif
	#ifdef AUDIO_F32LSB
		static constexpr auto F32LSB = AUDIO_F32LSB;
		#undef AUDIO_F32LSB
	#endif
	#ifdef AUDIO_S32
		static constexpr auto S32 = AUDIO_S32;
		#undef AUDIO_S32
	#endif
	#ifdef AUDIO_S32MSB
		static constexpr auto S32MSB = AUDIO_S32MSB;
		#undef AUDIO_S32MSB
	#endif
	#ifdef AUDIO_S32LSB
		static constexpr auto S32LSB = AUDIO_S32LSB;
		#undef AUDIO_S32LSB
	#endif
	
	#ifdef AUDIO_S16
		static constexpr auto S16 = AUDIO_S16;
		#undef AUDIO_S16
	#endif
	#ifdef AUDIO_U16
		static constexpr auto U16 = AUDIO_U16;
		#undef AUDIO_U16
	#endif
	#ifdef AUDIO_S16MSB
		static constexpr auto S16MSB = AUDIO_S16MSB;
		#undef AUDIO_S16MSB
	#endif
	#ifdef AUDIO_U16MSB
		static constexpr auto U16MSB = AUDIO_U16MSB;
		#undef AUDIO_U16MSB
	#endif
	#ifdef AUDIO_S16LSB
		static constexpr auto S16LSB = AUDIO_S16LSB;
		#undef AUDIO_S16LSB
	#endif
	#ifdef AUDIO_U16LSB
		static constexpr auto U16LSB = AUDIO_U16LSB;
		#undef AUDIO_U16LSB
	#endif
	#ifdef AUDIO_S8
		static constexpr auto S8 = AUDIO_S8;
		#undef AUDIO_S8
	#endif
	#ifdef AUDIO_U8
		static constexpr auto U8 = AUDIO_U8;
		#undef AUDIO_U8
	#endif
	
}

#ifdef SDL_AUDIOCVT_MAX_FILTERS
	static constexpr auto AUDIOCVT_MAX_FILTERS = SDL_AUDIOCVT_MAX_FILTERS;
	#undef SDL_AUDIOCVT_MAX_FILTERS
#endif

#ifdef SDL_MIX_MAXVOLUME
	static constexpr auto MIX_MAXVOLUME = SDL_MIX_MAXVOLUME;
	#undef SDL_MIX_MAXVOLUME
#endif
