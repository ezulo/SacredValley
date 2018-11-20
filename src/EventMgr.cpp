#include "EventMgr.h"

EventMgr::EventMgr() {}

EventMgr::~EventMgr() {}

void EventMgr::loop(sf::RenderWindow window, StateMgr stateMgr) {
	sf::Event event;
	while (window.pollEvent(event)) {
		//Key Presses
		if (event.type == sf::KeyPressed 
				|| event.type == sf::KeyReleased) {
			stateMgr.receive_event(event);
		}
		//Mouse Clicks
		if (event.type == sf::MouseButtonPressed 
				|| event.type == sf::MouseButtonReleased) {
			stateMgr.receive_event(event);
		//Mouse Movement
		if (event.type == sf::MouseMoved) {
			stateMgr.receive_event(event)
		}
	}
}
