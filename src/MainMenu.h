#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"
#include "../components/InputMgr.h"

//standard:
//game states need to have included all new game states they
//will create. in the case of "New Game"...
#include "Overworld.h"
#include "TextObject.h"
#include "StaticSpriteObject.h"

using namespace std;

class MainMenu : public GameState {
  public:
    void load_assets();
    void  loop();
    void  receive_event(sf::Event* event);
    MainMenu();
    ~MainMenu();
  private:
    TextObject* gameHeader;
    TextObject* optionBoxes[4];
	StaticSpriteObject* pointer;
    int selection;
};

#endif
