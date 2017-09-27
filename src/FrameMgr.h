#ifndef FRAMEMGR_H
#define FRAMEMGR_H

#include <states/GameFrame.h>
#include <states/GreenCircle.h>
#include <Event.h>
#include <stack>

class FrameMgr {
  public:
    void init();
    int  loop();
    int  transmit_event(Event *event);
    void push_frame(GameFrame *frame);
    void pop_frame();
    GameFrame* get_current_frame();
    StateMgr();
  private:
    void update_frame();
    unique_ptr<stack<GameFrame*>> frames;
    GameFrame* currentFrame;
}

#endif
