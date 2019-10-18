#pragma once
#include <iostream>
#include <string>
class Component
{
public:
	Component() {};
	virtual void update() { std::cout << "ERROR: Virtual update ran." << std::endl; }
	virtual std::string getType() { return "Error"; }
	std::string type;
};