#include "DisplayModule.h"

DisplayModule::DisplayModule(ApplicationConfig& cfg) {
	gameWindow = new sf::RenderWindow(
		sf::VideoMode(cfg->get_prop("xres"), cfg->get_prop("yres")), 
		"SFML_SacredValley"
	);
	gameWindow->setFramerateLimit(cfg->get_prop["framerateLimit"]);
}

DisplayModule::~DisplayModule() {
	delete gameWindow;
}

void DisplayModule::add_object(GameObject* newObj) {
	activeObjects.push_back(newObj);
}

void DisplayModule::purge_objects() {
	activeObjects.clear();
}

void DisplayModule::draw() {
	return;
}
