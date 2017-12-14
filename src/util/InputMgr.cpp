#include "InputMgr.h"

const int powArr[4] = {1, 2, 4, 8};
const int directionTable[16] = {
  -1,
  0,
  2,
  1,
  4,
  -1,
  3,
  2,
  6,
  7,
  -1,
  0,
  5,
  6,
  4,
  -1
};

int InputMgr::translate_dir() 
{
  int sum = 0;
  sum += inputMap["dir_right"] * 1;
  sum += inputMap["dir_down"] * 2;
  sum += inputMap["dir_left"] * 4;
  sum += inputMap["dir_up"] * 8;
  return directionTable[sum];
}

void InputMgr::listen()
{
  //direction block
  inputMap["dir_right"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
  inputMap["dir_down"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
  inputMap["dir_left"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
  inputMap["dir_up"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
  inputMap["dir"] = translate_dir();
  inputMap["z"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Z); 
  inputMap["x"] = sf::Keyboard::isKeyPressed(sf::Keyboard::X);
}

int InputMgr::getInput(const std::string q)
{
  if (inputMap.find(q) == inputMap.end()) {
    return -1;
  }
  else return inputMap[q];
}

InputMgr::InputMgr()
{
  inputMap["dir_right"] = 0;
  inputMap["dir_down"] = 0;
  inputMap["dir_left"] = 0;
  inputMap["dir_up"] = 0;
  inputMap["dir"] = -1;
  inputMap["z"] = 0;
  inputMap["x"] = 0; 
}

InputMgr::~InputMgr()
{
}


