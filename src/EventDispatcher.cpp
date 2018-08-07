#include "EventDispatcher.h"

int EventDispatcher::send_event(sf::Event* event)
{
  return stateMgr->transmit_event(event); 
}

EventDispatcher::EventDispatcher(StateMgr* sMptr, sf::RenderWindow* gWptr)
{
  stateMgr = sMptr;
  gameWindow = gWptr;
}

EventDispatcher::~EventDispatcher()
{
  
}
