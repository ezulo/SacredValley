#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include <queue>
#include "../Game.h"
#include "../Event.h"

class GameFrame{
  public:
    virtual void init();
    virtual void loop();
    virtual int  event(Event* event);
    virtual void draw();
    
  protected:
    GameFrame() {}
};

#endif
