#include "GameState.h"

GameState:GameState(EventMgr* eMgr) {
	eventMgr = eMgr;
}

sf::Font GameState::load_font(const std::string fontName) 
{
  return resourceMgr->get_font(fontName);
}
