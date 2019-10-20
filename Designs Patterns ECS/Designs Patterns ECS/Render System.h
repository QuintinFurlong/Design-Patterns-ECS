#pragma once
#include "Entity.h"
#include "Position Component.h"

class RenderSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update(SDL_Renderer* t_render) {
		for (int i = 0; i < entities.size(); i++)
		{
			for (int i2 = 0; i2 < entities.at(i).getComponents().size(); i2++)
			{
				if (entities.at(i).getComponents().at(i2)->getType() == "Position")
				{
					std::string name = "Assets/" + entities.at(i).id + ".bmp";
					SDL_Surface* image = SDL_LoadBMP(name.c_str());
					SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(t_render, image);
					SDL_Rect dstrect = { entities.at(i).getComponents().at(i2)->getX(), entities.at(i).getComponents().at(i2)->getY(), 300, 200 };
					SDL_RenderCopy(t_render, sdl_texture, NULL , &dstrect);

				}
			}
		}
	}
};