#ifndef STATEMGR_H
#define STATEMGR_H

// std
#include <stack>
#include <queue>
// util headers
#include "Event.h"
// game state headers
#include "GameState.h"
#include "MainMenu.h"

class StateMgr {
	public:
		StateMgr();
		~StateMgr();
		void loop();
		void push_event(Event* event);
		GameState* get_current_state();
	private:
		bool pop_state();
		void push_state(GameState* state);
		void purge_states();
		void process_events();
		std::stack<GameState*> stateStack;
		std::queue<Event*> eventQueue;
};

#endif
