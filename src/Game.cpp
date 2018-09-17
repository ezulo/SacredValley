#include "Game.h"

void Game::init() {
	// Do game prep stuff here not pertaining
	// directly to Game class...e.g. pop a state on here,
	return;
}

void Game::run()
{
	// Change while condition based on events received...
	while (loop()) {
		continue;	
	}
	return;
}

void Game::loop() 
{
	stateMgr->loop();
}

Game::Game() 
{
	//we want this to be variable at some point in time...
	appConfig = new ApplicationConfig();
	stateMgr = new StateMgr(gameWindow, inputMgr, resourceMgr);
	resourceMgr = new ResourceMgr("../../resource");
	eventMgr = new EventMgr(this);
	displayMod = new DisplayModule(appConfig);
	audioMod = new AudioModule();
	inputMod = new InputModule(eventMgr);
	init();
}

Game::~Game()
{
  gameWindow->close();
  delete appConfig;
  delete gameWindow;
  delete eventDispatcher;
  delete stateMgr;
  delete inputMgr;
  delete resourceMgr;
}

