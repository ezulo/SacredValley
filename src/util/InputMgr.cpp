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
  for (int i = 0; i < 4; i++) {
    sum += powArr[i] * dirButtonArr[i];
  }
  return directionTable[sum];
}

void InputMgr::listen()
{
  //direction block
  dirButtonArr[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
  dirButtonArr[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
  dirButtonArr[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
  dirButtonArr[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
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
  inputMap["dir"] = -1;
  inputMap["z"] = 0;
  inputMap["x"] = 0; 
}

InputMgr::~InputMgr()
{
}


