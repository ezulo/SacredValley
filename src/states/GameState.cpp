#include "GameState.h"

sf::Font GameState::load_font(const std::string fontName) 
{
  return resourceMgr->get_font(fontName);
}
