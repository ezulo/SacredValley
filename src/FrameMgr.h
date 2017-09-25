#ifndef FRAMEMGR_H
#define FRAMEMGR_H

#include <states/GameState.h>
#include <states/GreenCircle.h>
#include <stack>

class FrameMgr {
  public:
    void init();
    int  loop();
    void change_frame(GameState *state);
    void push_frame(GameState *state);
    GameState* pop_frame();
    StateMgr();
  private:
    unique_ptr<stack<GameState*>> frames;
}

#endif
