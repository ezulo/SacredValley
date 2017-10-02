#include "EventDispatcher.h"

int EventDispatcher::send_event(Event* event)
{
  return frameMgr->transmit_event(event); 
}

EventDispatcher::EventDispatcher(FrameMgr* fMptr, sf::RenderWindow* gWptr)
{
  frameMgr = fMptr;
  gameWindow = gWptr;
}

EventDispatcher::~EventDispatcher()
{
  
}
