#ifndef REDCIRCLE_H
#define REDCIRCLE_H

#include <SFML/Graphics.hpp>
#include "GameFrame.h"

using namespace std;

class RedCircle : public GameFrame {
  public:
    void handle_events();
    void draw();
    int  loop();
    int  event(Event* event);
    RedCircle(sf::RenderWindow *wptr);
    ~RedCircle();
  private:
    sf::CircleShape shape;
    float xVelo, yVelo;
    bool flux;
    int red;
};

#endif
