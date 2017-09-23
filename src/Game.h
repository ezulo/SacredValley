#ifndef GAME_H
#define GAME_H
#include <stack>
#include <queue>

using namespace std;

enum Runflag {
  RUNFLAG_LOADING,
  RUNFLAG_STARTED
}

class Game {
  
  public:
    void init();
    void cleanup();
    void loop();
    bool is_running();
    void quit();
    Game();
  
  private:
    StateMgr stateMgr;
    queue<Event> eventQueue;
    Runflag runflag;
}

#endif
