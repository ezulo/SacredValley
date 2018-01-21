#ifndef OVERWORLD_H
#define OVERWORLD_H

#include "GameState.h"
#include "../util/InputMgr.h"

using namespace std;

class Overworld : public GameState {
  public:
    int handle_events();
    int load_assets();
    int draw();
    int loop();
    int event(sf::Event* event);
    GameState* resolve_transition(int code);
  private:
    //don't worry so much about save game functionality right now
    int pause_menu();
    int save_game();
    int load_game();
};

#endif
