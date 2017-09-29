#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include <queue>
#include "../Event.h"

class GameFrame{
  public:
    virtual void init();
    virtual void draw();
    virtual int  loop();
    virtual int  event(Event* event);
    
  protected:
    GameFrame() {}
};

#endif
