#include "Game.h"

void Game::run()
{
	// Change while condition based on events received...
	while (true) {
		loop();
	}
	return;
}

void Game::loop() 
{
	return stateMgr->loop();
}

Game::Game() 
{
	//we want this to be variable at some point in time...
	int framerateLimit = 60;
	gameWindow = new sf::RenderWindow(sf::VideoMode(800,600), "SFML_SacredValley");
	gameWindow->setFramerateLimit(framerateLimit);
	inputMgr = new InputMgr();
	stateMgr = new StateMgr(gameWindow, inputMgr, resourceMgr);
	resourceMgr = new ResourceMgr("../../resource");
	init();
}

Game::~Game()
{
  gameWindow->close();
  delete gameWindow;
  delete eventDispatcher;
  delete stateMgr;
  delete inputMgr;
  delete resourceMgr;
}

