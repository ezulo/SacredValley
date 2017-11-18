#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"

using namespace std;

class MainMenu : public GameState {
  public:
    void handle_events();
    void load_assets();
    void draw();
    int  loop();
    int  event(sf::Event* event);
    MainMenu(sf::RenderWindow *wptr, InputMgr *iMptr);
    ~MainMenu();
  private:
    sf::CircleShape cursor;
    sf::Text optionBoxes[4];
    float xVelo, yVelo;
    bool flux;
    int red;
};

#endif
