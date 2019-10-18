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
	Entity player, alien, dog, cat;
	HealthComponent hc;
	PositionComponent pc;
	InputComponent ic;
	player.addComponent(&hc);
	alien.addComponent(&hc);
	dog.addComponent(&hc);

	player.addComponent(&pc);
	alien.addComponent(&pc);
	dog.addComponent(&pc);
	cat.addComponent(&pc);

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

	while (true) {
		hs.update();
		cs.update();
		as.update();
		rs.update();
	}
	return EXIT_SUCCESS;
}