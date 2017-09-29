#include "Game.h"

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
        gameWindow->close();
	quit();
      }
    }
    loop();
  }
  quit();
  return;
}

int Game::loop() 
{
  frameMgr->loop();
}

bool Game::is_running() 
{
  return (runflag == RUNFLAG_STARTED);
}

void Game::quit() 
{
  cleanup(); 
}

void Game::cleanup()
{
  //delete any data unaccounted for
  free(frameMgr);
  free(eventDispatcher);
  free(gameWindow);
}

Game::Game() 
{
  eventDispatcher = new EventDispatcher(frameMgr, gameWindow);
  gameWindow = new sf::RenderWindow(sf::VideoMode(800,600), "SFML Works!");
  frameMgr = new FrameMgr(gameWindow);
  init();
}

Game::~Game(){
}

