#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <SFML/Graphics.hpp>
#include "StateMgr.h"
#include "../states/GameState.h"

class EventDispatcher 
{
  public:
    int send_event(sf::Event* event);
    EventDispatcher(StateMgr* fMptr, sf::RenderWindow* gWptr);
    ~EventDispatcher();
  private:
    StateMgr* stateMgr;
    sf::RenderWindow* gameWindow;
};

#endif
