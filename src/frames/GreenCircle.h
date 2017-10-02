#ifndef GREENCIRCLE_H
#define GREENCIRCLE_H

#include <SFML/Graphics.hpp>
#include "GameFrame.h"

using namespace std;

class GreenCircle : public GameFrame {
  public:
    void draw();
    int  loop();
    int  event(Event* event);
    GreenCircle(sf::RenderWindow *wptr);
    ~GreenCircle();
  private:
    sf::RenderWindow *game_window;
    sf::CircleShape shape;
    bool flux;
    int green;
};

#endif
