#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"
#include "../util/InputMgr.h"

//standard:
//game states need to have included all new game states they
//will create. in the case of "New Game"...
#include "RedCircle.h"

using namespace std;

class MainMenu : public GameState {
  public:
    int handle_events();
    int load_assets();
    int draw();
    int  loop();
    int  event(sf::Event* event);
    GameState* resolve_transition(int code);
    bool key_listen(int key);
    MainMenu(sf::RenderWindow* wptr, InputMgr* iMptr, ResourceMgr* rMptr);
    ~MainMenu();
  private:
    sf::Font font;
    sf::CircleShape cursor;
    sf::Text gameHeader;
    sf::Text optionBoxes[4];
    bool keyState[4][2];
    bool keyDown[4];
    int selection;
};

#endif
