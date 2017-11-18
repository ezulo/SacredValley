#ifndef STATEMGR_H
#define STATEMGR_H

#include <stack>
#include <SFML/Graphics.hpp> 
#include "InputMgr.h"
#include "ResourceMgr.h"

//all game state headers must be included below
//unless we find a better way to do this...
#include "../states/GameState.h"
#include "../states/RedCircle.h"
#include "../states/MainMenu.h"

class StateMgr {
  public:
    int  loop();
    int  transmit_event(sf::Event* event);
    GameState* get_current_state();
    StateMgr(sf::RenderWindow* wPtr, InputMgr* iMptr, ResourceMgr* rMptr);
    ~StateMgr();
  private:
    void purge_states();
    void push_state(GameState* state);
    void pop_state();
    stack<GameState*> states;
    sf::RenderWindow* gameWindow;
    InputMgr* inputMgr;
    ResourceMgr* resourceMgr;
};

#endif
