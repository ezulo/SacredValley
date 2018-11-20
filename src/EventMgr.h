#ifndef EVENTMGR_H
#define EVENTMGR_H

#include <SFML/Window.hpp>
#include "StateMgr.h"

class EventMgr {
	public:
		EventMgr();
		~EventMgr();
		void loop(sf::RenderWindow window, StateMgr stateMgr);
};

#endif
