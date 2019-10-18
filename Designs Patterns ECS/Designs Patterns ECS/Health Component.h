#pragma once
#include "Component.h"
#include <iostream>
#include <string>

class HealthComponent : public Component
{
public:
	HealthComponent() : health(100), type("Health"){}
	int getHealth() { return health; }
	void setHealth(int t_health) { this->health = t_health; }
	void update() { std::cout << " has " << std::to_string(this->getHealth()) << " health" << std::endl; }
	std::string getType() { return type; }
private:
	int health;
	std::string type;
};