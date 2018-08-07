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
    ResourceMgr* resourceMgr;
    EventDispatcher* eventDispatcher;
    sf::RenderWindow* gameWindow;
};

#endif
