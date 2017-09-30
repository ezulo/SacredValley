#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "EventDispatcher.h"
#include "FrameMgr.h"

using namespace std;

enum Runflag {
  RUNFLAG_LOADING,
  RUNFLAG_STARTED,
  RUNFLAG_QUIT
};

class Game {
  
  public:
    void init();
    void run();
    int loop();
    bool is_running();
    void quit();
    void cleanup();
    Game();
    ~Game();
  
  private:
    FrameMgr* frameMgr;
    EventDispatcher* eventDispatcher;
    sf::RenderWindow* gameWindow;
    Runflag runflag;
};

#endif
