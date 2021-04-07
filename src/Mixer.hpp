#ifndef INK_SDLWRAPPER_MIXER_STRUCT_WRAPPER_CLASS_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_MIXER_STRUCT_WRAPPER_CLASS_HEADER_FILE_GUARD

#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	struct Mixer {
		
		public: using Music = internal::MIX::Mix_Music*;
		public: using Chunk = internal::MIX::Mix_Chunk*;
		
		public: explicit
		Mixer(	int frequency = internal::MIX::DEFAULT_FREQUENCY, internal::Uint16 format = internal::MIX::DEFAULT_FORMAT,
				int channels = internal::MIX::DEFAULT_CHANNELS, int chunksize = 1024)
		{ init(frequency, format, channels, chunksize); }
		
		public: explicit
		Mixer(	int frequency, internal::Uint16 format,
				int channels, int chunksize, char const* device, int allowed_changes)
		{ init(frequency, format, channels, chunksize, device, allowed_changes); }
		
		public:
		~Mixer()
		{ deinit(); }
		
		
		
		public: static inline Music
		LoadMusic(std::string_view audio_file_path)
		{ return internal::MIX::Mix_LoadMUS(audio_file_path.cbegin()); }
		
		public: static inline auto
		PlayMusic(Music music, int loops = 1)
		{ return internal::MIX::Mix_PlayMusic(music, loops); }
		
		
		
		public: static inline int
		init(	int frequency, internal::Uint16 format,
				int channels, int chunksize)
		{ return internal::MIX::Mix_OpenAudio(frequency, format, channels, chunksize); }
		
		public: static inline int
		init(	int frequency, internal::Uint16 format, int channels,
				int chunksize, char const* device, int allowed_changes)
		{ return internal::MIX::Mix_OpenAudioDevice(frequency, format, channels, chunksize, device, allowed_changes); }
		
		public: static inline void
		deinit()
		{ return internal::MIX::Mix_CloseAudio(); }
		
	};
	
}

#endif
