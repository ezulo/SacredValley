#ifndef REDCIRCLE_H
#define REDCIRCLE_H

#include "GameState.h"
#include "../util/InputMgr.h"

using namespace std;

class RedCircle : public GameState {
  public:
    void handle_events();
    void load_assets();
    void draw();
    int  loop();
    int  event(sf::Event* event);
    RedCircle(sf::RenderWindow* wptr, InputMgr* iMptr, ResourceMgr* rMptr);
    ~RedCircle();
  private:
    sf::CircleShape shape;
    float xVelo, yVelo;
    bool flux;
    int red;
};

#endif
