#pragma once
#include "Component.h"
#include <SDL.h>

class InputComponent : public Component
{
public:
	InputComponent() : type("Input") {}
	void update() { SDL_WaitEvent(&sdl_event); }
	int getEvent() { 
		if (sdl_event.type == SDL_KEYDOWN)
			return sdl_event.key.keysym.sym; 
		return 0;
	}
	std::string getType() { return type; }
private:
	SDL_Event sdl_event;
	std::string type;
};