
#include <thread>
#include <stdio.h>
#include <type_traits>

#define SDL_MAIN_HANDLED
#include "SDLWrapper.hpp"

int main() {
	
	auto SDL = ink::SDL::SDL().SDL_video().Init();
	
	auto wnd = SDL.CreateWindow().Init("Window", ink::SDL::internal::WINDOWPOS_UNDEFINED, ink::SDL::internal::WINDOWPOS_UNDEFINED, 100, 100);
	auto rnd = SDL.CreateRenderer().accelerated().Init(wnd);
	
	auto e = ink::SDL::internal::SDL_Event();
	bool	running = true;
	while (	running	) {
		while(ink::SDL::internal::SDL_PollEvent(&e)!=0) switch(e.type) {
			case ink::SDL::internal::SDL_QUIT: running = false; break;
		}
		
	}
	
	
	return 0;
}

