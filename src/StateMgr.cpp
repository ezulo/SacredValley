#include "StateMgr.h"

/* 
PUBLIC
*/

StateMgr::StateMgr()
{
	GameState *init_frame = new MainMenu();
	push_state(init_frame);
}

StateMgr::~StateMgr()
{
	// leave room her to serialize states...
	// need to empty states
	purge_states();
}


void StateMgr::loop()
{
	// Main loop, called every time frame
	process_events();
}

void StateMgr::push_event(Event event) {
	eventQueue.push(event);
}


GameState& StateMgr::get_current_state()
{
	return stateStack.top();
}

/*
PRIVATE
*/

bool StateMgr::pop_state()
{
	if (stateStack.empty())
		return false;
	stateStack.pop();
	return true;
}

void StateMgr::push_state(GameState *state)
{			 
	stateStack.push(state);
}

void StateMgr::purge_states()
{
	while (!states.empty()) {
		GameState* tmp = stateStack.top();
		stateStack.pop();
		delete tmp;
	}
}

