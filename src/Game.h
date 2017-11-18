#ifndef GAME_H
#define GAME_H

//libraries
#include <stack>
#include <SFML/Graphics.hpp>

//all util modules
#include "util/EventDispatcher.h"
#include "util/InputMgr.h"
#include "util/StateMgr.h"
#include "util/ResourceMgr.h"

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
    StateMgr* stateMgr;
    InputMgr* inputMgr;
    ResourceMgr* resourceMgr;
    EventDispatcher* eventDispatcher;
    sf::RenderWindow* gameWindow;
    Runflag runflag;
};

#endif
