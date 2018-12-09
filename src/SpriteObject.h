#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Object.h"

//SpriteObject is an implementation of Object that contains a sprite.
//The sprite can either be static (non-moving), in which case it will
//contain no animation data, or it can be dynamic, in which case it will
//contain animation data.

class SpriteObject : Object {
	public:
		SpriteObject(const std::string textureFileName) : Object();
		~SpriteObject();
		void set_pos(double x, double y);
		void set_pos(sf::Vector2<double> newPos);
		void set_angle(double newTheta);
		void set_mirror(bool mir);
	protected:
		sf::Texture* texture;
		sf::Sprite* sprite;
};

#endif
