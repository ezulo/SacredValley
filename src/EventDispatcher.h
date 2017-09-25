#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <Game.h>
#include <Event.h>

class EventDispatcher 
{
  public:
    send_event(Event event, GameFrame *frame);
    EventDispatcher();
}

#endif
