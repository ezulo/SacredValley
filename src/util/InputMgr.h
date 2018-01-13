#ifndef INPUTMGR_H
#define INPUTMGR_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

class InputMgr {
  public:
    void listen();
    bool get_input(const std::string q, int singlePress = 0);
    InputMgr();
    ~InputMgr();
  private:
    int translate_dir();
    int get_key_state(const std::string key, bool keyPressed);
    std::map<std::string, int> inputMap;
};

#endif
