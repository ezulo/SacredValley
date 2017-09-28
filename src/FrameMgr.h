#ifndef FRAMEMGR_H
#define FRAMEMGR_H

#include <stack>
#include "frames/GameFrame.h"
#include "frames/GreenCircle.h"
#include "Event.h"

class FrameMgr {
  public:
    void init();
    int  loop();
    void quit();
    int  transmit_event(Event *event);
    void push_frame(GameFrame *frame);
    void pop_frame();
    GameFrame* get_current_frame();
    FrameMgr();
  private:
    void update_frame();
    unique_ptr<stack<GameFrame*>> frames;
    GameFrame* currentFrame;
    ~FrameMgr();
};

#endif
