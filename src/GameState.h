#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <set>

#include "InputMgr.h"
#include "ResourceMgr.h"
#include "Object.h"
#include "Event.h"

typedef std::set<Object*> ObjectSet;

class GameState {
  public:
	GameState(EventMgr* eMgr);
	~GameState();
    //functionality defined by states
    virtual void load_assets() = 0;
    virtual void loop() = 0;
    virtual void receive_event(sf::Event* event) = 0;
    //global functionality
    sf::Font load_font(const std::string fontName);
  protected:
    virtual void  draw() = 0;
	ObjectSet objects;
	EventMgr* eventMgr;
};

#endif
