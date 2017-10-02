#include <iostream>
#include "GreenCircle.h"

void GreenCircle::draw()
{
  //create glow effect
  if (green >= 255) {
    flux = false;
  } else if (green <= 0) {
    flux = true;
  }
  if (flux) {
    green++;
  } else {
    green--;
  }

  shape.setFillColor(sf::Color(0, green, 0));
  
  game_window->clear();
  game_window->draw(shape);
  game_window->display();
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
  //no events handled here, class is just for testing
  return 0;
}

GreenCircle::GreenCircle(sf::RenderWindow *wptr)
{
  game_window = wptr;
  shape = sf::CircleShape(100.f);
  shape.setFillColor(sf::Color(0, 255, 0));
}

GreenCircle::~GreenCircle()
{
}
