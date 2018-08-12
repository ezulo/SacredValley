#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ApplicationConfig.h"
#include "EventDispatcher.h"
#include "StateMgr.h"
#include "ResourceMgr.h"
#include "DisplayModule.h"
#include "AudioModule.h"
#include "InputModule.h"
#include <stack>

using namespace std;

class Game {
  public:
    void run();
    int loop();
    Game();
    ~Game();
  
  private:
	DisplayModule* displayM;
	AudioModule* audioM;
	InputModule* inputM;
    StateMgr* stateMgr;
    ResourceMgr* resourceMgr;
    EventDispatcher* eventDispatcher;
};

#endif
