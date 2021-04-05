
#include <thread>
#include <stdio.h>

#define SDL_MAIN_HANDLED
#include "SDLWrapper.hpp"

int main() {
	namespace SDL = ink::SDL;
	
	auto subsys = ink::SDL::Subsystem<>{}
		.SDL_everything()
		.init();
	
	SDL::Frame frame; // Allows for safe forward declaration.
	frame = SDL::Frame("Title", 1440, 810, SDL::FlagCtr<SDL::Frame>{}.RESIZABLE());
	
	bool running = true;
	while (running) {
		
		while (frame.poll_events()) switch(frame.event().type) {
			case SDL::internal::SDL_QUIT:
				running = false;
			break;
		}
		
		frame.DrawClear(SDL::RGB_Preset::WHITE);
		
		frame.DrawUpdate();
		
	}
	
	
	
	return 0;
}

