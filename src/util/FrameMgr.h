#ifndef FRAMEMGR_H
#define FRAMEMGR_H

#include <stack>
#include <SFML/Graphics.hpp> 
#include "InputMgr.h"
#include "../frames/GameFrame.h"
#include "../frames/RedCircle.h"

class FrameMgr {
  public:
    int  loop();
    int  transmit_event(sf::Event* event);
    GameFrame* get_current_frame();
    FrameMgr(sf::RenderWindow* wPtr, InputMgr* iMptr);
    ~FrameMgr();
  private:
    void purge_frames();
    void push_frame(GameFrame* frame);
    void pop_frame();
    stack<GameFrame*> frames;
    sf::RenderWindow* gameWindow;
    InputMgr* inputMgr;
};

#endif
