#include "GreenCircle.h"
#include <iostream>

void GreenCircle::init()
{
  return;
}

int GreenCircle::loop()
{
  //do nothing else here, just for testing
  draw();
  return 0;
}

int GreenCircle::event(Event* event)
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
  std::cout << "GreenCircle state instantiated";
  game_window = wptr;
  shape = sf::CircleShape(100.f);
  std::cout << "Shape created.";
}
