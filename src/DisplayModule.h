#ifndef DISPLAYMODULE_H
#define DISPLAYMODULE_H

#include "GameObject.h"
#include "ApplicationConfig.h"

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <stdexcept>
#include <vector>


// DisplayModule will handle the rendering of any GameObject objects. GameState
// should still have pointers to the GameObjects, and states should be in full
// control of interacting with objects.. Placing them in the activeObject 
// vector will render them onto the game window.
class DisplayModule {
	public:
		DisplayModule(ApplicationConfig& cfg);
		~DisplayModule();
		void add_object(GameObject* newObj)
		void purge_objects();
		void loop();
	private:
		void draw();
		void draw_object(GameObject* obj);
		sf::RenderWindow* gameWindow;	
		vector<GameObject*> activeObjects;
};

#endif
