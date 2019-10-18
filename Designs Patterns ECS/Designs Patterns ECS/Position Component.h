#pragma once
#include "Component.h"
#include <iostream>
#include <string>

class PositionComponent : public Component
{
public:
	PositionComponent() : x(50), y(50), type("Position") {}
	int getX() { return x; }
	int getY() { return y; }
	void setPosition(float t_x, float t_y) { this->x = t_x; this->y = t_y;}
	void update() { std::cout << " is at X: " << std::to_string(this->getX()) << " Y: " 
		<< std::to_string(this->getY()) << std::endl; }
	std::string getType() { return type; }
private:
	float x, y;
	std::string type;
};