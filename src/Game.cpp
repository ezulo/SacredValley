#include <Game.h>
#include <GameState.h>

void Game::init()
{  
  run();
}

void Game::run()
{
  while (game_window.isOpen()) {
    sf::Event event;
    while (game_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        game_window.close();
	quit();
    }
    loop();
  }
}

int Game::loop() 
{
  stateMgr->loop();
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
  free(stateMgr);
  free(eventDispatcher);
  free(game_window);
}

Game::Game() {
  stateMgr = new StateMgr();
  eventDispatcher = new EventDispatcher();
  game_window = new sf::RenderWindow(sf::VideoMode(800,600), "SFML Works!");
  init();
}

