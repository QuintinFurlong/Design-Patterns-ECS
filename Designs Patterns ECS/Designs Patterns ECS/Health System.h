#pragma once
#include "Entity.h"
#include <typeinfo>

class HealthSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() {
		for (int i = 0; i < entities.size();i++)
		{
			for (int i2 = 0; i2 < entities.at(i).getComponents().size(); i2++)
			{
				if (entities.at(i).getComponents().at(i2)->getType() == "Health")
				{
					//entities.at(i).getComponents().at(i2)->update();
				}
			}
		}
	}
};