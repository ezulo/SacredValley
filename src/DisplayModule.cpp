#include "DisplayModule.h"

DisplayModule::DisplayModule(ApplicationConfig& cfg) {
	gameWindow = new sf::RenderWindow(
		sf::VideoMode(cfg->get_prop("xres"), cfg->get_prop("yres")), 
		"SFML_SacredValley"
	);
	gameWindow->setFramerateLimit(cfg->get_prop["framerateLimit"]);
}

DisplayModule::~DisplayModule() {
	gameWindow->close();
	purge_objects();
	delete gameWindow;
}

void DisplayModule::add_object(GameObject* newObj) {
	activeObjects.push_back(newObj);
}

void DisplayModule::purge_objects() {
	for (
		std::vector<GameObject*>::iterator it = activeObjects.begin();
		it != activeObjects.end();
		++it
	) {
		delete (*it);
	}
	activeObjects.clear();

}

void DisplayModule::draw() {
	std::for_each(activeObjects.begin(), activeObjects.end(), draw_object);
	gameWindow->display();
	return;
}

void DisplayModule::draw_object(GameObject* obj) {
	if (gameWindow->isOpen()) {
		if (obj->get_visible()) {
			gameWindow->draw(obj->get_sprite());
		}
	}
	else {
		throw std::runtime_error("Error from renderer: game window inactive.") 
	}
	return;
}
