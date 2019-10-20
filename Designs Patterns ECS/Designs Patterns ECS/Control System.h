#pragma once
#include "Entity.h"

class ControlSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() {
		for (int i = 0; i < entities.size(); i++)
		{
			for (int i2 = 0; i2 < entities.at(i).getComponents().size(); i2++)
			{
				if (entities.at(i).getComponents().at(i2)->getType() == "input")
				{
					int input = entities.at(i).getComponents().at(i2)->getEvent();
					int x = 0;
					int y = 0;
					if (input != 0)
					{
						if (input == SDLK_LEFT)
						{
							x--;
						}
						else if (input == SDLK_RIGHT)
						{
							x++;
						}
						else if (input == SDLK_UP)
						{
							y--;
						}
						else if (input == SDLK_DOWN)
						{
							y++;
						}
						for (int i2 = 0; i2 < entities.at(i).getComponents().size(); i2++)
						{
							if (entities.at(i).getComponents().at(i2)->getType() == "position")
							{
								Component* current = entities.at(i).getComponents().at(i2);
								current->setPosition(current->getX() + x, current->getY() + y);
							}
						}
					}
				}
			}
		}
	}
};