#include <iostream>
#include "RedCircle.h"

const float DEF_VELO = 10.0;

void RedCircle::handle_events(){
  float mult = 0.7071067;
  switch (inputMgr->getInput("dir")){
    case -1:
      xVelo = 0;
      yVelo = 0;
      break;
    case 0:
      xVelo = DEF_VELO;
      yVelo = 0;
      break;
    case 1:
      xVelo = DEF_VELO * mult;
      yVelo = -DEF_VELO * mult;
      break;
    case 2:
      xVelo = 0;
      yVelo = -DEF_VELO;
      break;
    case 3:
      xVelo = -DEF_VELO * mult;
      yVelo = -DEF_VELO * mult;
      break;
    case 4:
      xVelo = -DEF_VELO;
      yVelo = 0;
      break;
    case 5:
      xVelo = -DEF_VELO * mult;
      yVelo = DEF_VELO * mult;
      break;
    case 6:
      xVelo = 0;
      yVelo = DEF_VELO;
      break;
    case 7:
      xVelo = DEF_VELO * mult;
      yVelo = DEF_VELO * mult;
      break;
    default:
      std::cout << "ERROR PARSING DIRECTION" << endl;
      xVelo = 0;
      yVelo = 0;
      break;
  }
  return;
}

void RedCircle::load_assets() {
}

void RedCircle::draw()
{
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
  
  gameWindow->clear();
  gameWindow->draw(shape);
  gameWindow->display();
  return;
}

int RedCircle::loop()
{
  inputMgr->listen();
  handle_events();
  draw();
  return 0;
}

int RedCircle::event(sf::Event* event)
{
  return 0;
}

RedCircle::RedCircle(sf::RenderWindow* wptr, InputMgr* iMptr, ResourceMgr* rMptr):GameState(wptr, iMptr, rMptr)
{
  shape = sf::CircleShape(20.f);
  shape.setFillColor(sf::Color(255, 0, 0));
  xVelo = 0;
  yVelo = 0;
}

RedCircle::~RedCircle()
{
}
