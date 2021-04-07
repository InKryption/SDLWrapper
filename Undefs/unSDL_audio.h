#ifdef SDL_AUDIO_BITSIZE
	static constexpr auto AUDIO_BITSIZE(auto x)
	{
		return SDL_AUDIO_BITSIZE(x);
		#undef SDL_AUDIO_BITSIZE
	}
#endif

#ifdef SDL_AUDIO_ISFLOAT
	static constexpr auto AUDIO_ISFLOAT(auto x)
	{
		return SDL_AUDIO_ISFLOAT(x);
		#undef SDL_AUDIO_ISFLOAT
	}
#endif

#ifdef SDL_AUDIO_ISBIGENDIAN
	static constexpr auto AUDIO_ISBIGENDIAN(auto x)
	{
		return SDL_AUDIO_ISBIGENDIAN(x);
		#undef SDL_AUDIO_ISBIGENDIAN
	}
#endif

#ifdef SDL_AUDIO_ISSIGNED
	static constexpr auto AUDIO_ISSIGNED(auto x)
	{
		return SDL_AUDIO_ISSIGNED(x);
		#undef SDL_AUDIO_ISSIGNED
	}
#endif

#ifdef SDL_AUDIO_ISINT
	static constexpr auto AUDIO_ISINT(auto x)
	{
		return SDL_AUDIO_ISINT(x);
		#undef SDL_AUDIO_ISINT
	}
#endif

#ifdef SDL_AUDIO_ISLITTLEENDIAN
	static constexpr auto AUDIO_ISLITTLEENDIAN(auto x)
	{
		return SDL_AUDIO_ISLITTLEENDIAN(x);
		#undef SDL_AUDIO_ISLITTLEENDIAN
	}
#endif

#ifdef SDL_AUDIO_ISUNSIGNED
	static constexpr auto AUDIO_ISUNSIGNED(auto x)
	{
		return SDL_AUDIO_ISUNSIGNED(x);
		#undef SDL_AUDIO_ISUNSIGNED
	}
#endif


#ifdef SDL_AUDIO_MASK_BITSIZE
	static constexpr auto AUDIO_MASK_BITSIZE = SDL_AUDIO_MASK_BITSIZE;
	#undef SDL_AUDIO_MASK_BITSIZE
#endif

#ifdef SDL_AUDIO_MASK_DATATYPE
	static constexpr auto AUDIO_MASK_DATATYPE = SDL_AUDIO_MASK_DATATYPE;
	#undef SDL_AUDIO_MASK_DATATYPE
#endif

#ifdef SDL_AUDIO_MASK_ENDIAN
	static constexpr auto AUDIO_MASK_ENDIAN = SDL_AUDIO_MASK_ENDIAN;
	#undef SDL_AUDIO_MASK_ENDIAN
#endif

#ifdef SDL_AUDIO_MASK_SIGNED
	static constexpr auto AUDIO_MASK_SIGNED = SDL_AUDIO_MASK_SIGNED;
	#undef SDL_AUDIO_MASK_SIGNED
#endif



namespace AUDIO {
	
	#ifdef AUDIO_U16SYS
		static constexpr auto U16SYS = AUDIO_U16SYS;
		#undef AUDIO_U16SYS
	#endif
	
	#ifdef AUDIO_S16SYS
		static constexpr auto S16SYS = AUDIO_S16SYS;
		#undef AUDIO_S16SYS
	#endif
	
	#ifdef AUDIO_S32SYS
		static constexpr auto S32SYS = AUDIO_S32SYS;
		#undef AUDIO_S32SYS
	#endif
	
	#ifdef AUDIO_F32SYS
		static constexpr auto F32SYS = AUDIO_F32SYS;
		#undef AUDIO_F32SYS
	#endif
	
	
	#ifdef AUDIO_S32MSB
		static constexpr auto S32MSB = AUDIO_S32MSB;
		#undef AUDIO_S32MSB
	#endif
	
	#ifdef AUDIO_S32
		static constexpr auto S32 = AUDIO_S32;
		#undef AUDIO_S32
	#endif
	
	#ifdef AUDIO_F32MSB
		static constexpr auto F32MSB = AUDIO_F32MSB;
		#undef AUDIO_F32MSB
	#endif
	
	#ifdef AUDIO_F32
		static constexpr auto F32 = AUDIO_F32;
		#undef AUDIO_F32
	#endif
	
	#ifdef AUDIO_U16SYS
		static constexpr auto U16SYS = AUDIO_U16SYS;
		#undef AUDIO_U16SYS
	#endif
	
	#ifdef AUDIO_S16SYS
		static constexpr auto S16SYS = AUDIO_S16SYS;
		#undef AUDIO_S16SYS
	#endif
	
	#ifdef AUDIO_S32SYS
		static constexpr auto S32SYS = AUDIO_S32SYS;
		#undef AUDIO_S32SYS
	#endif
	
	#ifdef AUDIO_S32LSB
		static constexpr auto S32LSB = AUDIO_S32LSB;
		#undef AUDIO_S32LSB
	#endif
	
	#ifdef AUDIO_F32SYS
		static constexpr auto F32SYS = AUDIO_F32SYS;
		#undef AUDIO_F32SYS
	#endif
	
	#ifdef AUDIO_F32LSB
		static constexpr auto F32LSB = AUDIO_F32LSB;
		#undef AUDIO_F32LSB
	#endif
	
	
	
	#ifdef AUDIO_U8
		static constexpr auto U8 = AUDIO_U8;
		#undef AUDIO_U8
	#endif
	
	#ifdef AUDIO_S8
		static constexpr auto S8 = AUDIO_S8;
		#undef AUDIO_S8
	#endif
	
	#ifdef AUDIO_U16MSB
		static constexpr auto U16MSB = AUDIO_U16MSB;
		#undef AUDIO_U16MSB
	#endif
	
	#ifdef AUDIO_S16MSB
		static constexpr auto S16MSB = AUDIO_S16MSB;
		#undef AUDIO_S16MSB
	#endif
	
	#ifdef AUDIO_U16
		static constexpr auto U16 = AUDIO_U16;
		#undef AUDIO_U16
	#endif
	
	#ifdef AUDIO_U16LSB
		static constexpr auto U16LSB = AUDIO_U16LSB;
		#undef AUDIO_U16LSB
	#endif
	
	#ifdef AUDIO_S16
		static constexpr auto S16 = AUDIO_S16;
		#undef AUDIO_S16
	#endif
	
	#ifdef AUDIO_S16LSB
		static constexpr auto S16LSB = AUDIO_S16LSB;
		#undef AUDIO_S16LSB
	#endif
	
}

#ifdef SDL_AUDIO_ALLOW_ANY_CHANGE
	static constexpr auto AUDIO_ALLOW_ANY_CHANGE = SDL_AUDIO_ALLOW_ANY_CHANGE;
	#undef SDL_AUDIO_ALLOW_ANY_CHANGE
#endif

#ifdef SDL_AUDIO_ALLOW_FREQUENCY_CHANGE
	static constexpr auto AUDIO_ALLOW_FREQUENCY_CHANGE = SDL_AUDIO_ALLOW_FREQUENCY_CHANGE;
	#undef SDL_AUDIO_ALLOW_FREQUENCY_CHANGE
#endif

#ifdef SDL_AUDIO_ALLOW_FORMAT_CHANGE
	static constexpr auto AUDIO_ALLOW_FORMAT_CHANGE = SDL_AUDIO_ALLOW_FORMAT_CHANGE;
	#undef SDL_AUDIO_ALLOW_FORMAT_CHANGE
#endif

#ifdef SDL_AUDIO_ALLOW_CHANNELS_CHANGE
	static constexpr auto AUDIO_ALLOW_CHANNELS_CHANGE = SDL_AUDIO_ALLOW_CHANNELS_CHANGE;
	#undef SDL_AUDIO_ALLOW_CHANNELS_CHANGE
#endif

#ifdef SDL_AUDIO_ALLOW_SAMPLES_CHANGE
	static constexpr auto AUDIO_ALLOW_SAMPLES_CHANGE = SDL_AUDIO_ALLOW_SAMPLES_CHANGE;
	#undef SDL_AUDIO_ALLOW_SAMPLES_CHANGE
#endif

#ifdef SDL_AUDIOCVT_MAX_FILTERS
	static constexpr auto AUDIOCVT_MAX_FILTERS = SDL_AUDIOCVT_MAX_FILTERS;
	#undef SDL_AUDIOCVT_MAX_FILTERS
#endif


#ifdef SDL_AUDIOCVT_PACKED
	#define Rstringi(x) #x
	#define stringi(x) Rstringi(x)
	
	static constexpr auto AUDIOCVT_PACKED = stringi(SDL_AUDIOCVT_PACKED);
	
	#undef stringi
	#undef Rstringi
	
	#undef SDL_AUDIOCVT_PACKED
#endif

#ifdef SDL_LoadWAV
	static inline auto LoadWAV(const char* file, SDL_AudioSpec* spec, Uint8** audio_buf, Uint32* audio_len)
	{
		return SDL_LoadWAV(file, spec, audio_buf, audio_len);
		#undef SDL_LoadWAV
	}
#endif

#ifdef SDL_MIX_MAXVOLUME
	static constexpr auto MIX_MAXVOLUME = SDL_MIX_MAXVOLUME;
	#undef SDL_MIX_MAXVOLUME
#endif
