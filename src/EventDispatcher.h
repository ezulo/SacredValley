#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "FrameMgr.h"
#include "Event.h"
#include "frames/GameFrame.h"

class EventDispatcher 
{
  public:
    int send_event(Event event, GameFrame *frame);
    EventDispatcher(FrameMgr* fMptr, sf::RenderWindow* gWptr);
  private:
    FrameMgr* frameMgr;
    sf::RenderWindow* gameWindow;
};

#endif
