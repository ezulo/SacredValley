#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include <queue>
#include "../Event.h"

class GameFrame{
  public:
    virtual void draw() = 0;
    virtual int  loop() = 0;
    virtual int  event(Event* event) = 0;
  protected:
    sf::RenderWindow *game_window;
    GameFrame(sf::RenderWindow *wptr) {
      game_window = wptr;
    }
};

#endif
