#ifndef INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD
#define INK_SDLWRAPPER_FRAME_WINDOW_RENDERER_WRAPPER_CLASS_HEADER_FILE_GUARD

#include "SDLWrapper.hpp"

namespace ink::SDL {
	
	//template<bool Shaped = false>
	class Frame {
		
		public: constexpr
		Frame()
		{}
		
		
		
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
