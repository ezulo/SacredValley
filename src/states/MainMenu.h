#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"
#include "../util/InputMgr.h"

using namespace std;

class MainMenu : public GameState {
  public:
    void handle_events();
    void load_assets();
    void draw();
    int  loop();
    int  event(sf::Event* event);
    bool key_listen(int key);
    MainMenu(sf::RenderWindow* wptr, InputMgr* iMptr, ResourceMgr* rMptr);
    ~MainMenu();
  private:
    sf::CircleShape cursor;
    sf::Text gameHeader;
    sf::Text optionBoxes[4];
    bool keyState[4][2];
    bool keyDown[4];
    int selection;
};

#endif
