
#include <thread>
#include <stdio.h>
#include <type_traits>
#include <cstring>

#define SDL_MAIN_HANDLED
#include "SDLWrapper.hpp"

namespace SDL = ink::SDL;

int main() {
	using namespace SDL::internal;
	
	auto subsys = ink::SDL::Subsystem<>{}
		.SDL_everything()
		.IMG_png()
		.init();
	
	SDL::Frame frame; // Allows for safe forward declaration.
	frame = SDL::Frame("Title", 100, 100, SDL::Frame::FlagCtr{}.RESIZABLE());
	
	bool running = true;
	
	while (running) {
		
		while (frame.poll_events()) switch(frame.event().type) {
			case SDL_QUIT:
				running = false;
			break;
		}
		
		
		
	}
	
	
	
	return 0;
}

