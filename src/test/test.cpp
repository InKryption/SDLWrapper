
#include <thread>
#include <stdio.h>

#define SDL_MAIN_HANDLED
#include "SDLWrapper.hpp"

int main() {
	ink::SDL::internal::SDL_Init(SDL_INIT_EVERYTHING);
	auto wnd = ink::SDL::internal::SDL_CreateWindow("", 100, 100, 100, 100, ink::SDL::internal::SDL_WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI);
	
	
	
	std::this_thread::sleep_for(std::chrono::seconds(2));
	
	ink::SDL::internal::SDL_DestroyWindow(wnd);
	
	return 0;
}
