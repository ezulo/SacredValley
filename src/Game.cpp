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
    if (loop() == -1) return;
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
  eventDispatcher = new EventDispatcher(stateMgr, gameWindow);
  gameWindow = new sf::RenderWindow(sf::VideoMode(800,600), "SFML Works!");
  gameWindow->setFramerateLimit(60);
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

