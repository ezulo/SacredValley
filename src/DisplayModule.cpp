#include "DisplayModule.h"

DisplayModule::DisplayModule(WindowProperties props) {
	window = new sf::RenderWindow(
		sf::VideoMode(props.getXRes(), props.getYRes()), 
		"SFML_SacredValley"
	);
	window->setFramerateLimit(props.getFramerateLimit());
}

DisplayModule::~DisplayModule() {
	delete window;
}

void DisplayModule::add_object(GameObject* newObj) {
	activeObjects.push_back(newObj);
}

void DisplayModule::purge_objects() {
	activeObjects.clear();
}
