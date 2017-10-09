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
  return frameMgr->loop();
}

bool Game::is_running() 
{
  return (runflag == RUNFLAG_STARTED);
}


Game::Game() 
{
  eventDispatcher = new EventDispatcher(frameMgr, gameWindow);
  gameWindow = new sf::RenderWindow(sf::VideoMode(800,600), "SFML Works!");
  gameWindow->setFramerateLimit(60);
  frameMgr = new FrameMgr(gameWindow);
  init();
}

Game::~Game()
{
  gameWindow->close();
  delete gameWindow;
  delete eventDispatcher;
  delete frameMgr;
}

