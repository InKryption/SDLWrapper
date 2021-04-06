
#include <thread>
#include <stdio.h>

#define SDL_MAIN_HANDLED
#include "SDLWrapper.hpp"

int main() {
	namespace SDL = ink::SDL;
	
	auto subsys = ink::SDL::Subsystem<>{}
		.SDL_everything()
		.IMG_png()
	.init();
	
	SDL::Frame frame{"Title", 1440, 810,
		frame.MakeFlags()
			.ACCELERATED()
			.RESIZABLE(),
		
	};
	
	auto tex = SDL::internal::IMG::IMG_LoadTexture(frame.renderer(), "assets/Menu/Title.png");
	
	bool running = true;
	while (running) {
		
		while (frame.poll_events()) switch(frame.event().type) {
			case SDL::internal::SDL_QUIT:
				running = false;
			break;
		}
		
		frame.DrawClear(SDL::RGB_Preset::WHITE);
		frame.DrawTexture<int>(tex, SDL::Rect{0, 0, 100, 100}, nullptr);
		frame.DrawUpdate();
		
		
	}
	
	
	
	return 0;
}

