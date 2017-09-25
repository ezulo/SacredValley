#ifndef GAME_H
#define GAME_H
#include <stack>
#include <SFML/Graphics.hpp>
#include <EventDispatcher.h>

using namespace std;

enum Runflag {
  RUNFLAG_LOADING,
  RUNFLAG_STARTED
}

class Game {
  
  public:
    void init();
    void run();
    void loop();
    bool is_running();
    void quit();
    void cleanup();
    Game();
  
  private:
    StateMgr *stateMgr;
    EventDispatcher *eventDispatcher;
    sf::RenderWindow *game_window;
    Runflag runflag;
}

#endif
