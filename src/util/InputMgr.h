#ifndef INPUTMGR_H
#define INPUTMGR_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class InputMgr {
  public:
    int translate_dir();
    void listen();
    int getInput(const std::string q);
    InputMgr();
    ~InputMgr();
  private:
    std::map<std::string, int> inputMap;
};

#endif
