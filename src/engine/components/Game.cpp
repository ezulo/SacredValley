#include "Game.h"
#include <iostream>

void Game::init()
{  
  run();
}

void Game::run()
{
  while (gameWindow->isOpen()) {
    sf::Event event;
    while (gameWindow->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        return;
      }
    }
    int loopSignal = loop();
    if (loopSignal == -4) {
      std::cout << "No states remaining. Terminating." << endl;
      return;
    }
    if (loopSignal == -3) {
      std::cout << "A fatal error has occured. Terminating." << endl;
      return;
    }  
  }
  return;
}

int Game::loop() 
{
  return stateMgr->loop();
}

bool Game::is_running() 
{
  return (runflag == RUNFLAG_STARTED);
}

Game::Game() 
{
  //we want this to be variable at some point in time...
  int framerateLimit = 60;

  eventDispatcher = new EventDispatcher(stateMgr, gameWindow);
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

