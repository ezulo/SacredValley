#include "Avatar.h"

Avatar::Avatar(
    sf::Vector2f startPosition, 
    sf::Vector2f spriteSize, 
    std::string sprite_path) 
{
  position = startPosition;
  size = spriteSize;
  //Now to load sprite...
  sf::Texture texture;
  texture.loadFromFile(sprite_path); 
  sprite.setTexture(texture);
  sprite.setTextureRect(IntRect(0, 0, size.x, size.y));
  visible = true;
}

Avatar::~Avatar() 
{
};

void set_visible(
  bool vis)
{
  visible = vis;
  return;
}

bool Avatar::is_on_tile (
  sf::Vector2f p0, 
  sf::Vector2f p1)
{
  //return true if all vertices of avatar are inside a tile.
  //good condition: true! it means we're standing on something real.
  return true;
}

bool Avatar::obstacle_collision (
  sf::Vector2f p0, 
  sf::Vector2f p1) 
{
  return false;
}

void Avatar::animate_next_frame (
  int mode,
  int inc)
{
  //0, 33, 66, 99, 132, 165, 198.... 
  //might make changes to this in the future...
  int x_focus = (inc * size.x);
  int y_focus = (mode * size.y);
  sprite.setTextureRect(sf::IntRect(x_focus, y_focus, size.x, size.y));
}

void Avatar::transition_mode (
    int new_mode)
{
  if ((new_mode > 7) || (new_mode < 0)) {
    std::cout << "Error: mode " << new_mode << " out of range." << endl;
  }
  inc = 0;
}
