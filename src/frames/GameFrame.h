#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include <queue>
#include "../Event.h"

class GameFrame{
  public:
    virtual void init();
    virtual void loop();
    virtual int  event(Event* event);
    virtual void draw();
    void change_frame(Game* game, GameFrame frame) {
      game->change_frame(frame);
    }
    
  protected:
    GameFrame() {}
}

#endif
