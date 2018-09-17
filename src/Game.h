#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ApplicationConfig.h"
#include "StateMgr.h"
#include "ResourceMgr.h"
#include "EventMgr.h"
#include "DisplayModule.h"
#include "AudioModule.h"
#include "InputModule.h"

// Game is the class that will have the following responsibilities:
//   1. Initialize the game, contain the game loop, and terminate the game
//   2. Pass events (from EventMgr) to StateMgr, to propagate the changes from
//      the events in the game state. (e.g., if player presses right arrow,
//      a "KeyPress" event will go from InputMod -> EventMgr -> here, where it
//      will be sent to StateMgr at the end of the frame)
//   3. 

class Game {
  public:
	  void init();
      void run();
      int loop();
      Game();
      ~Game();
  
  private:
	  ApplicationConfig* appConfig;
      EventMgr* eventMgr;
      StateMgr* stateMgr;
      ResourceMgr* resourceMgr;
	  DisplayModule* displayMod;
	  AudioModule* audioMod;
	  InputModule* inputMod;
};

#endif
