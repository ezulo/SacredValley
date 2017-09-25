#ifndef GREENCIRCLE_H
#define GREENCIRCLE_H

#include<GameFrame.h>
#include<SFML/Graphics.hpp>

using namespace std;

class GreenCircle : public GameFrame {
  public:
    void init();
    void loop();
    int  event();
    void draw();
    GreenCircle(sf::RenderWindow *wptr);
  private:
    sf::RenderWindow *game_window;
    //below are assets, just for testing purposes
    sf:CircleShape shape;
}

#endif
