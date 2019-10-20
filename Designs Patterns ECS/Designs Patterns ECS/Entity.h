#pragma once
#include "Component.h"
#include <vector>

class Entity
{
public:
	Entity(std::string t_id) : id(t_id) {}
	void addComponent(Component* c) {components.push_back(c);}
	void removeComponent(Component c) { /*loop then pop*/}
	std::vector<Component*> getComponents() { return components; }
	std::string id;
private:
	std::vector<Component*> components;
};