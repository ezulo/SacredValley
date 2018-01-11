#ifndef STATEMGR_H
#define STATEMGR_H

#include <stack>
#include <SFML/Graphics.hpp> 

//util headers
#include "InputMgr.h"
#include "ResourceMgr.h"
//game state headers
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
    bool push_state(GameState* state);
    bool pop_state();
    void purge_states();
    stack<GameState*> states;
    bool state_lock;
    sf::RenderWindow* gameWindow;
    InputMgr* inputMgr;
    ResourceMgr* resourceMgr;
};

#endif
