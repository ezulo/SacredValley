#ifndef RESOURCEMGR_H
#define RESOURCEMGR_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>

class ResourceMgr {
  public:
    sf::Font get_font(const std::string fontName);
    ResourceMgr(const std::string fontPath);
    ~ResourceMgr();
  private:
    std::string path;
};

#endif
