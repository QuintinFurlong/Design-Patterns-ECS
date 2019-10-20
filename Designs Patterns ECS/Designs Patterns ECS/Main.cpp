#include "Entity.h"
#include "Health Component.h"
#include "Position Component.h"
#include "Input Component.h"
#include "Health System.h"
#include "Ai System.h"
#include "Control System.h"
#include "Render System.h"
#include <vector>
#include <SDL.h>

int main(int argc, char* args[])
{
	Entity player("player");
	Entity alien("alien");
	Entity dog("dog");
	Entity cat("cat");
	PositionComponent pc[4];
	HealthComponent hc[3];
	InputComponent ic;

	pc[0].setPosition(10, 10);
	pc[1].setPosition(350, 10);
	pc[2].setPosition(10, 350);
	pc[3].setPosition(350, 350);
	player.addComponent(&pc[0]);
	alien.addComponent(&pc[1]);
	dog.addComponent(&pc[2]);
	cat.addComponent(&pc[3]);

	player.addComponent(&hc[0]);
	alien.addComponent(&hc[1]);
	dog.addComponent(&hc[2]);

	player.addComponent(&ic);

	HealthSystem hs;
	hs.addEntity(player);
	hs.addEntity(alien);
	hs.addEntity(dog);
	ControlSystem cs;
	cs.addEntity(player);
	cs.addEntity(alien);
	cs.addEntity(dog);
	cs.addEntity(cat);
	AiSystem as;
	as.addEntity(player);
	as.addEntity(alien);
	as.addEntity(dog);
	as.addEntity(player);
	RenderSystem rs;
	rs.addEntity(player);
	rs.addEntity(alien);
	rs.addEntity(dog);
	rs.addEntity(cat);

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* sdl_window = SDL_CreateWindow("SDL2 Displaying Image",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 700, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(sdl_window, -1, 0);


	while (true) {
		SDL_UpdateWindowSurface(sdl_window);
		hs.update();
		cs.update();
		as.update();
		rs.update(renderer);
		SDL_RenderPresent(renderer);
	}
	return EXIT_SUCCESS;
}