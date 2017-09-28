#ifndef GREENCIRCLE_H
#define GREENCIRCLE_H

#include<SFML/Graphics.hpp>
#include"GameFrame.h"

using namespace std;

class GreenCircle : public GameFrame {
  public:
    void init();
    void loop();
    int  event(Event* event);
    void draw();
    GreenCircle(sf::RenderWindow *wptr);
  private:
    sf::RenderWindow *game_window;
    //below are assets, just for testing purposes
    sf::CircleShape shape;
};

#endif
