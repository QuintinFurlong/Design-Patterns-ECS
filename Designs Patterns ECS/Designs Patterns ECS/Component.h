#pragma once
#include <iostream>
#include <string>
class Component
{
public:
	Component() {};
	virtual void update() { std::cout << "ERROR: Virtual update ran." << std::endl; }
	virtual std::string getType() { return "Error"; }
	virtual int getX() { return 0; }
	virtual int getY() { return 0; }
	virtual int getHealth() { return 0; }
	virtual int getEvent() { return 0; }
	virtual void setPosition(float t_x, float t_y) {}
	std::string type;
};