
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
	
	decltype(subsys) test;
	
	SDL::Frame frame{"Title", 1440, 810,
		SDL::FlagCtr<SDL::Frame>{}
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
		SDL::internal::SDL_RenderCopy(frame.renderer(), tex, nullptr, nullptr);
		frame.DrawUpdate();
	}
	
	
	
	return 0;
}

