#include "ResourceMgr.h"

sf::Font ResourceMgr::get_font(const std::string fontName) {
  sf::Font newFont;
  if (!newFont.loadFromFile(path + fontName)) {
    //throw an error here
    std::cout << "Font not found: " << fontName << std::endl;
  }
  return newFont;
}

ResourceMgr::ResourceMgr() {
  this->path = "../../resource";
}

ResourceMgr::ResourceMgr(const std::string resourcePath) {
  this->path = resourcePath;
}

ResourceMgr::~ResourceMgr() {

}
