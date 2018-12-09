#ifndef REDCIRCLE_H
#define REDCIRCLE_H

#include "GameState.h"
#include "../components/InputMgr.h"

using namespace std;

// THIS IS JUST A TEST CLASS
// TO TEST INPUT AND SHIT
class RedCircle : public GameState {
  public:
    void load_assets();
    void loop();
    void receive_event(sf::Event* event);
    RedCircle();
    ~RedCircle();
  private:
    void draw();
    sf::CircleShape shape;
    float xVelo, yVelo;
    bool flux;
    int red;
};

#endif
