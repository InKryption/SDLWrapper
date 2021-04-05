
#include <thread>
#include <stdio.h>
#include <type_traits>
#include <cstring>
#include <vector>

#define SDL_MAIN_HANDLED
#include "SDLWrapper.hpp"

namespace SDL = ink::SDL;

int main() {
	
	
	
	
	auto subsys = ink::SDL::Subsystem<>{}
		.SDL_everything()
		.init();
	
	SDL::Frame frame; // Allows for safe forward declaration.
	frame = SDL::Frame("Title", 1440, 810, SDL::FlagCtr<SDL::Frame>{}.RESIZABLE());
	
	bool running = true;
	
	std::vector<SDL::Point<int>> pArr = {
		{1,2},
		{300,400},
		{20,30}
	};
	
	while (running) {
		
		while (frame.poll_events()) switch(frame.event().type) {
			case SDL::internal::SDL_QUIT:
				running = false;
			break;
		}
		
		SDL::internal::SDL_SetRenderDrawColor(frame.renderer());
		
	}
	
	
	
	return 0;
}

