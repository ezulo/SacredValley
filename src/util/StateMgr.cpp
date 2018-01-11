#include <iostream>
#include "StateMgr.h"

/* 
PUBLIC
*/

int StateMgr::loop()
{
  if (get_current_state() != NULL){ 
    int loopSignal = get_current_state()->loop();
    switch(loopSignal) {
      case -3:
        purge_states(); 
        break;
      case -2:
        pop_state();
        if (states.empty()) return -4;
        break;
      case -1:
        break;
      default:
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
  if (get_current_state()){
    return get_current_state()->event(event);
  }
  return 0;
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
