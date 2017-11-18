#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics.hpp>
#include <queue>
#include "../util/InputMgr.h"
#include "../util/ResourceMgr.h"

class GameState{
  public:
    //functionality defined by states
    virtual void handle_events() = 0;
    virtual void load_assets(const std::string fontName) = 0;
    virtual void draw() = 0;
    virtual int  loop() = 0;
    virtual int  event(sf::Event* event);
    //global functionality
    sf::Font load_asset_font();
  protected:
    //members
    sf::RenderWindow *game_window;
    InputMgr* inputMgr;
    ResourceMgr* resourceMgr;
    GameState(sf::RenderWindow *wptr, InputMgr* iMptr, ResourceMgr* rMptr) 
    {
      game_window = wptr;
      inputMgr = iMptr;
      resourceMgr = rMptr;
    }
};

#endif
