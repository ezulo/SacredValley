#ifndef AVATAR_H
#define AVATAR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Obstacle.h"

class Avatar {
  public:
    Avatar(sf::Vector2f startPosition, sf::Vector2f size, std::string sprite_path);
    ~Avatar();
    void set_visible(bool vis);
    void move(sf::Vector2f dir);
  private:
    bool is_on_tile(sf::Vector2f p0, sf::Vector2f p1);
    bool obstacle_collision(sf::Vector2f p0, sf::Vector2f p1);
    void animate_next_frame();
    void transition_mode(int new_mode);
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f size;
    std::vector<Obstacle> obstacleList;
    sf::Sprite avatarSprite;
    float walkSpeedPrimary, walkSpeedSecondary;
    bool visible;
    //animation vars below
    int mode_period;
    int mode;
    int inc;
}

#endif
