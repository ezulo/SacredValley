#ifndef STATEMGR_H
#define STATEMGR_H

#include <stack>

#include "GameState.h"
#include "MainMenu.h"
#include "Overworld.h"
#include "DisplayModule.h"

class StateMgr {
	public:
		StateMgr();
		~StateMgr();
		void loop();
		void receive_event(sf::Event event);
		GameState* get_current_state();
	private:
		bool pop_state();
		void push_state(GameState* state);
		void purge_states();
		std::stack<GameState*> stateStack;
		DisplayModule* displayMod;
};

#endif
