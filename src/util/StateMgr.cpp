#include <iostream>
#include "StateMgr.h"

/* 
PUBLIC
*/

int StateMgr::loop()
{
  //loop codes:
  //-4: no states found
  //-3: fatal error, purge states
  //-2: remove state from stack
  //-1: all good
  //0-99: state transition code
  if (!states.empty()){ 
    int loopSignal = get_current_state()->loop();
    switch(loopSignal) {
      case -3:
        purge_states(); 
        break;
      case -2:
        std::cout << "State popped." << endl;
        pop_state();
        if (states.empty()) return -4;
        break;
      case -1:
        break;
      default:
        std::cout << "New state: " << loopSignal << endl;
        GameState* newState = get_current_state()->resolve_transition(loopSignal);
        if (newState != get_current_state()) {
          push_state(newState);
        }
        break;
    }
    return loopSignal;
  } else {
    return -4;
  }
}

int StateMgr::transmit_event(sf::Event *event)
{
  if (!states.empty()){
    return get_current_state()->event(event);
  }
  return -1;
}

GameState* StateMgr::get_current_state()
{
  return states.top();
}

StateMgr::StateMgr(sf::RenderWindow* wPtr, InputMgr* iMptr, ResourceMgr* rMptr)
{
  gameWindow = wPtr;
  inputMgr = iMptr;
  resourceMgr = rMptr;
  GameState *init_frame = new MainMenu(gameWindow, inputMgr, rMptr);
  push_state(init_frame);
}

StateMgr::~StateMgr()
{
  //need to empty states
  purge_states();
}

/*
PRIVATE
*/

void StateMgr::purge_states()
{
  while (!states.empty()) {
    GameState* tmp = states.top();
    states.pop();
    delete tmp;
  }
}

bool StateMgr::push_state(GameState *state)
{       
  states.push(state);
  return true;
}

bool StateMgr::pop_state()
{
  if (states.empty())
    return false;
  states.pop();
  return true;
}
