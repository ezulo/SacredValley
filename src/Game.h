#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "util/EventDispatcher.h"
#include "util/FrameMgr.h"
#include "util/InputMgr.h"

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
    Game();
    ~Game();
  
  private:
    FrameMgr* frameMgr;
    InputMgr* inputMgr;
    EventDispatcher* eventDispatcher;
    sf::RenderWindow* gameWindow;
    Runflag runflag;
};

#endif
