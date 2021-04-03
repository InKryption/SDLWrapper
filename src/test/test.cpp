
#include <thread>
#include <stdio.h>

#define SDL_MAIN_HANDLED 1
#include "SDLWrapper.hpp"

int main() {
	
	using namespace ink::SDL::internal;
	
	SDL_Init(INIT_EVERYTHING);
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
	SDL_Quit();
	
	return 0;
}

