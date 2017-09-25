#include <GreenCircle.h>
#include <SFML/Graphics.hpp>

void GreenCircle::init()
{
  return;
}

void GreenCircle::loop()
{
  //do nothing else here, just for testing
  draw();
  return;
}

int GreenCircle::event()
{
  //no events handled
  return 0;
}

void GreenCircle::draw()
{
  game_window->clear();
  game_window->draw(shape);
  game_window->display();
  return;
}

GreenCircle::GreenCircle(sf::RenderWindow *wptr) 
{
  game_window = wptr;
  shape = new sf::CircleShape(100,f);
}
