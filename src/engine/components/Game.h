#ifndef GAME_H
#define GAME_H

//libraries
#include <stack>
#include <SFML/Graphics.hpp>

//all util modules
#include "EventDispatcher.h"
#include "InputMgr.h"
#include "StateMgr.h"
#include "ResourceMgr.h"

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
