#ifndef REDCIRCLE_H
#define REDCIRCLE_H

#include "GameFrame.h"

using namespace std;

class RedCircle : public GameFrame {
  public:
    void handle_events();
    void draw();
    int  loop();
    int  event(sf::Event* event);
    RedCircle(sf::RenderWindow *wptr, InputMgr *iMptr);
    ~RedCircle();
  private:
    sf::CircleShape shape;
    float xVelo, yVelo;
    bool flux;
    int red;
};

#endif
