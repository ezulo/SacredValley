#include "StateMgr.h"

/* 
PUBLIC
*/

StateMgr::StateMgr() {
	GameState *init_frame = new MainMenu();
	push_state(init_frame);
}

StateMgr::~StateMgr() {
	// need to empty states
	purge_states();
}


void StateMgr::loop() {
	// Main loop, called every time frame
	process_events();
}

void receive_event(sf::Event event) {
	get_current_state->receive_event(event);
}


GameState& StateMgr::get_current_state() {
	return stateStack.top();
}

/*
PRIVATE
*/

bool StateMgr::pop_state() {
	if (stateStack.empty())
		return false;
	stateStack.pop();
	return true;
}

void StateMgr::push_state(GameState *state) { 
	stateStack.push(state);
}

void StateMgr::purge_states() {
	while (!states.empty()) {
		GameState* tmp = stateStack.top();
		stateStack.pop();
		delete tmp;
	}
}

