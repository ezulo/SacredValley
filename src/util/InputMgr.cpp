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

//for the inputMap structure:
//0 = key up, go to state 1 on key down
//1 = key down, go to state 2
//2 = key down, go to state 0 on key up 
//should be able to send flag to get_input() to get either:
//key currently down
//single key press

void InputMgr::listen()
{
  //direction block
  inputMap["dir_right"] = get_key_state("dir_right", sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
  inputMap["dir_down"] =  get_key_state("dir_down",  sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
  inputMap["dir_left"] =  get_key_state("dir_left",  sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
  inputMap["dir_up"] =    get_key_state("dir_up",    sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
  inputMap["z"] =         get_key_state("z",         sf::Keyboard::isKeyPressed(sf::Keyboard::Z)); 
  inputMap["x"] =         get_key_state("x",         sf::Keyboard::isKeyPressed(sf::Keyboard::X));
}

bool InputMgr::get_input(const std::string q, int singlePress)
{
  if (inputMap.find(q) == inputMap.end()) {
    return false;
  }
  if (!singlePress) {
    if ((inputMap[q] == 1) || (inputMap[q] == 2)) return true;
  }
  else {
    if (inputMap[q] == 1) return true;
  }
  return false;
}

int InputMgr::get_dir()
{
  int sum = 0;
  sum += inputMap["dir_right"] > 0 ? 1 : 0;
  sum += inputMap["dir_down"] > 0 ? 2 : 0;
  sum += inputMap["dir_left"] > 0 ? 4 : 0;
  sum += inputMap["dir_up"] > 0 ? 8 : 0;
  return directionTable[sum];
}

InputMgr::InputMgr()
{
  inputMap["dir_right"] = 0;
  inputMap["dir_down"]  = 0;
  inputMap["dir_left"]  = 0;
  inputMap["dir_up"]    = 0;
  inputMap["z"]         = 0;
  inputMap["x"]         = 0; 
}

InputMgr::~InputMgr()
{
}

int InputMgr::get_key_state(const std::string q, bool keyPressed)
{
  if (!keyPressed) {
    return 0;
  }
  if (inputMap[q] == 0) {
    return 1;
  }
  return 2;
}

