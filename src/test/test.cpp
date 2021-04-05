
#include <thread>
#include <stdio.h>
#include <type_traits>

#define SDL_MAIN_HANDLED
#include "SDLWrapper.hpp"

int main() {
	using namespace ink::SDL::internal;
	
	auto subsys = ink::SDL::Subsystem();
	
	auto wnd = SDL_CreateWindow("", 100, 100, 100, 100, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
	
	bool running = true;
	
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e) != 0) switch(e.type) {
			case SDL_QUIT:
				running = false;
			break;
		}
		
	}
	
	SDL_DestroyWindow(wnd);
	
	
	
	return 0;
}

