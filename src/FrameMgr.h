#ifndef FRAMEMGR_H
#define FRAMEMGR_H

#include <stack>
#include <SFML/Graphics.hpp> 
#include "frames/GameFrame.h"
#include "frames/GreenCircle.h"
#include "Event.h"

class FrameMgr {
  public:
    int  loop();
    void quit();
    int  transmit_event(Event* event);
    GameFrame* get_current_frame();
    FrameMgr(sf::RenderWindow* wPtr);
    ~FrameMgr();
  private:
    void purge_frames();
    void push_frame(GameFrame* frame);
    void pop_frame();
    stack<GameFrame*> frames;
    sf::RenderWindow* gameWindow;
};

#endif
