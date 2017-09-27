#include <EventDispatcher.h>
#include "Event.h"

int EventDispatcher::send_event(Event event)
{
  return frameMgr->getFrame()->event(event); 
}

EventDispatcher::EventDispatcher(FrameMgr* fMptr, sf::RenderWindow* gWptr)
{
  frameMgr = fMptr;
  gameWindow = gWptr;
}
