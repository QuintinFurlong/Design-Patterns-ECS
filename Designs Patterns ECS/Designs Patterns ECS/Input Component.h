#pragma once
#include "Component.h"
#include <SDL.h>

class InputComponent : public Component
{
public:
	InputComponent() : type("Input") {}
	void update() { std::cout << " is taking Input" << std::endl;}
	std::string getType() { return type; }
private:
	SDL_Event sdl_event;
	std::string type;
};