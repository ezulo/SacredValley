#ifndef REDCIRCLE_H
#define OVERWORLD_H 

#include "GameState.h"
#include "../components/InputMgr.h"

using namespace std;

class Overworld : public GameState {
  public:
    int handle_events();
    int load_assets();
    int draw();
    int loop();
    int event(sf::Event* event);
    GameState* resolve_transition(int code);
    Overworld(sf::RenderWindow* wptr, InputMgr* iMptr, ResourceMgr* rMptr);
    ~Overworld();
  private:
    sf::CircleShape shape;
    float xVelo, yVelo;
    bool flux;
    int red;
};

#endif
