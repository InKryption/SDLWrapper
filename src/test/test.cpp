
#include <thread>
#include <stdio.h>
#include <type_traits>

#define SDL_MAIN_HANDLED
#include "SDLWrapper.hpp"

template<typename T> struct rtup_impl;
template<typename T> static constexpr auto rtup = rtup_impl<T>::value;

template<template<auto...> typename T, auto... v> struct rtup_impl<T<v...>> { static constexpr auto value = std::make_tuple(v...); };

namespace SDL = ink::SDL;

int main() {
	using namespace SDL::internal;
	
	auto subsys = SDL::Subsystem()
		.SDL_everything()
		.IMG_png()
		.init();
	
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

