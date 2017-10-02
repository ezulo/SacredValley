#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <SFML/Graphics.hpp>
#include "FrameMgr.h"
#include "Event.h"
#include "frames/GameFrame.h"

class EventDispatcher 
{
  public:
    int send_event(Event* event);
    EventDispatcher(FrameMgr* fMptr, sf::RenderWindow* gWptr);
    ~EventDispatcher();
  private:
    FrameMgr* frameMgr;
    sf::RenderWindow* gameWindow;
};

#endif
