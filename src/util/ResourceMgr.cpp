#include "ResourceMgr.h"

sf::Font ResourceMgr::get_font(const std::string fontName) {
  sf::Font newFont;
  if (!newFont.loadFromFile(path + fontName)) {
    //throw an error here
    std::cout << "Font not found: " << fontName << std::endl;
  }
  return newFont;
}

ResouceMgr(const std::string resourcePath = "../../resource") {
  this->path = resourcePath;
}

~ResourceMgr() {

}
