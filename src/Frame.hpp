#ifndef INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD

#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	//template<bool Shaped = false>
	class Frame {
		
		// Functional Flag Constructor Structure. Each function toggles the window/renderer flag of the same name,
		// and returns a reference to the structure, allowing for chaining functions.
		public: struct FlagCtr {
			
			constexpr FlagCtr() {}
			
			constexpr FlagCtr& FULLSCREEN		()	{ wnd_flag ^= internal::SDL_WINDOW_FULLSCREEN;		return *this; }
			constexpr FlagCtr& OPENGL			()	{ wnd_flag ^= internal::SDL_WINDOW_OPENGL;			return *this; }
			constexpr FlagCtr& HIDDEN			()	{ wnd_flag ^= internal::SDL_WINDOW_HIDDEN;			return *this; }
			constexpr FlagCtr& BORDERLESS		()	{ wnd_flag ^= internal::SDL_WINDOW_BORDERLESS;		return *this; }
			constexpr FlagCtr& RESIZABLE		()	{ wnd_flag ^= internal::SDL_WINDOW_RESIZABLE;		return *this; }
			constexpr FlagCtr& MAXIMIZED		()	{ wnd_flag ^= internal::SDL_WINDOW_MAXIMIZED;		return *this; }
			constexpr FlagCtr& MINIMIZED		()	{ wnd_flag ^= internal::SDL_WINDOW_MINIMIZED;		return *this; }
			constexpr FlagCtr& INPUT_GRABBED	()	{ wnd_flag ^= internal::SDL_WINDOW_INPUT_GRABBED;	return *this; }
			constexpr FlagCtr& ALLOW_HIGHDPI	()	{ wnd_flag ^= internal::SDL_WINDOW_ALLOW_HIGHDPI;	return *this; }
			constexpr FlagCtr& VULKAN			()	{ wnd_flag ^= internal::SDL_WINDOW_VULKAN;			return *this; }
			constexpr FlagCtr& METAL			()	{ wnd_flag ^= internal::SDL_WINDOW_METAL;			return *this; }
			
			constexpr FlagCtr& SOFTWARE			()	{ rnd_flag ^= internal::SDL_RENDERER_SOFTWARE;		return *this; }
			constexpr FlagCtr& ACCELERATED		()	{ rnd_flag ^= internal::SDL_RENDERER_ACCELERATED;	return *this; }
			constexpr FlagCtr& PRESENTVSYNC		()	{ rnd_flag ^= internal::SDL_RENDERER_PRESENTVSYNC;	return *this; }
			constexpr FlagCtr& TARGETTEXTURE	()	{ rnd_flag ^= internal::SDL_RENDERER_TARGETTEXTURE;	return *this; }
			
			uint32_t wnd_flag{0}, rnd_flag{0};
		};
		
		public: constexpr
		Frame()
		{}
		
		public: [[nodiscard]]
		Frame(std::string_view title, int w, int h, FlagCtr const& flag_struct, int x = internal::WINDOWPOS_UNDEFINED, int y = internal::WINDOWPOS_UNDEFINED, int render_driver = -1)
		{ init(title.cbegin(), x, y, w, h, flag_struct.wnd_flag, render_driver, flag_struct.rnd_flag); }
		
		
		// Move will throw if acting as assignment to initialized Frame.
		public: void
		operator=(Frame && rval)
		{
			if (M_data != nullptr) throw;
			std::swap(M_data, rval.M_data);
		}
		
		public:
		Frame(Frame const&) = delete;
		
		private: void init(char const* title, int x, int y, int w, int h, ink::SDL::internal::Uint32 wnd_flags, int render_driver, ink::SDL::internal::Uint32 rnd_flags) {
			
			M_data = new impl;
			M_data->evt = internal::SDL_Event{};
			M_data->wnd = internal::SDL_CreateWindow(title, x, y, w, h, wnd_flags);
			M_data->rnd = internal::SDL_CreateRenderer(M_data->wnd, render_driver, rnd_flags);
			
		}
		
		private: void deinit() {
			
			internal::SDL_DestroyRenderer(M_data->rnd);
			internal::SDL_DestroyWindow(M_data->wnd);
			delete M_data;
			
		}
		
		private: struct impl {
			
			internal::SDL_Event evt{};
			internal::SDL_Window* wnd{nullptr};
			internal::SDL_Renderer* rnd{nullptr};
			constexpr auto active() const
			{ return ( wnd != nullptr ) && ( rnd != nullptr ); }
			
		}* M_data{nullptr};
		
	};
	
	//using ShapedFrame = Frame<true>;
	
}

#endif
