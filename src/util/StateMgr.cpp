#include <iostream>
#include "StateMgr.h"

/* 
PUBLIC
*/

int StateMgr::loop()
{
  if (get_current_state() != NULL){ 
    return get_current_state()->loop();
  } else {
    return -1;
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

void StateMgr::push_state(GameState *state)
{
  states.push(state);
  return;
}

void StateMgr::pop_state()
{
  states.pop();
  return;
}
