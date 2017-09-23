#include <Game.h>

Game::Game() {
  runflag = RUNFLAG_LOADING;
}

void Game::init()
{
  
}

void Game::cleanup()
{

}

void Game::loop() 
{

}

bool Game::is_running() 
{
  return (runflag == RUNFLAG_STARTED);
}

void Game::quit() 
{
  cleanup(); 
}
