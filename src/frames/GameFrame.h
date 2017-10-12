#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include <SFML/Graphics.hpp>
#include <queue>
#include "../util/InputMgr.h"

class GameFrame{
  public:
    virtual void draw() = 0;
    virtual int  loop() = 0;
    virtual int  event(sf::Event* event) = 0;
  protected:
    sf::RenderWindow *game_window;
    InputMgr* inputMgr;
    GameFrame(sf::RenderWindow *wptr, InputMgr* iMptr) 
    {
      game_window = wptr;
      inputMgr = iMptr;
    }
};

#endif
