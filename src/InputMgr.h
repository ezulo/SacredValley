#ifndef INPUTMGR_H
#define INPUTMGR_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

class InputMgr {
  public:
    InputMgr(EventMgr* eMgr);
    ~InputMgr();
		//will constuct key events to send to EventMgr
    void listenForInput();
    int get_analog_dir();
  private:
};

#endif
