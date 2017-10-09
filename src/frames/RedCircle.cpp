#include <iostream>
#include "RedCircle.h"

const float DEF_VELO = 10.0;
enum Direction {E,SE,S,SW,W,NW,N,NE,None};
const Direction DIRECTIONMAP[16] = {
  None,
  E,
  S,
  SE,
  W,
  None,
  SW,
  S,
  N,
  NE,
  None,
  E,
  NW,
  N,
  W,
  None
};

Direction translate_dir(int right, int down, int left, int up)
{
  //hard coding some of this makes for faster execution
  int dirMap[4] = {right, down, left, up};
  int powers[4] = {1, 2, 4, 8};
  int total = 0;
  for (int i = 0; i < 4; i++) {
    total += dirMap[i] * powers[i];
  }
  std::cout << total << endl;
  return DIRECTIONMAP[total];
}

void RedCircle::handle_events()
{
  bool keymap[6] = {false, false, false, false, false, false};
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    keymap[0] = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    keymap[1] = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    keymap[2] = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    keymap[3] = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
    keymap[4] = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
    keymap[5] = true;
  }

  float mult = 0.7071067; //approx 1 / sqrt(2)
  Direction trans = translate_dir(keymap[0], keymap[1], keymap[2], keymap[3]);
  switch (trans) {
    case E:
      std::cout << "E" << endl;
      xVelo = DEF_VELO;
      yVelo = 0;
      break;
    case SE:
      std::cout << "SE" << endl;
      xVelo = DEF_VELO * mult;
      yVelo = -DEF_VELO * mult;
      break;
    case S:
      std::cout << "S" << endl;
      xVelo = 0;
      yVelo = -DEF_VELO;
      break;
    case SW:
      std::cout << "SW" << endl;
      xVelo = -DEF_VELO * mult;
      yVelo = -DEF_VELO * mult;
      break;
    case W:
      std::cout << "W" << endl;
      xVelo = -DEF_VELO;
      yVelo = 0;
      break;
    case NW:
      std::cout << "NW" << endl;
      xVelo = -DEF_VELO * mult;
      yVelo = DEF_VELO * mult;
      break;
    case N:
      std::cout << "N" << endl;
      xVelo = 0;
      yVelo = DEF_VELO;
      break;
    case NE:
      std::cout << "NE" << endl;
      xVelo = DEF_VELO * mult;
      yVelo = DEF_VELO * mult;
      break;
    case None:
      std::cout << "Stay" << endl;
      xVelo = yVelo = 0;
      break;
  }

  return;
}

void RedCircle::draw()
{
  handle_events();

  //create glow effect
  if (red >= 255) {
    flux = false;
  } else if (red <= 126) {
    flux = true;
  }
  if (flux) {
    red++;
  } else {
    red--;
  }
  shape.setFillColor(sf::Color(red, 0, 0));

  //move sphere
  shape.move(xVelo, yVelo * -1);
  
  game_window->clear();
  game_window->draw(shape);
  game_window->display();
  return;
}

int RedCircle::loop()
{
  //do nothing else here, just for testing
  draw();
  return 0;
}

int RedCircle::event(Event* event)
{
  //no events handled here, class is just for testing
  return 0;
}

RedCircle::RedCircle(sf::RenderWindow *wptr):GameFrame(wptr)
{
  shape = sf::CircleShape(20.f);
  shape.setFillColor(sf::Color(255, 0, 0));
  xVelo = 0;
  yVelo = 0;
}

RedCircle::~RedCircle()
{
}
