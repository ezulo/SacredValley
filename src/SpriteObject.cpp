#include "SpriteObject.h"

SpriteObject::SpriteObject(const std::string textureFileName) : Object() {
	texture = new Texture();
	if (texture.loadFromFile(textureFileName)) {
		sprite = new Sprite(texture);
	}
	else {
		throw std::runtime_error(
			"Error from SpriteObject constructor: texture not found."
		);
	}
	isVisible = true;
}

SpriteObject::~SpriteObject() {
	delete texture;
	delete sprite;
}

void SpriteObject::set_pos(double x, double y) {
	pos.x = x;
	pos.y = y;
	sprite.setPosition(pos);
}

void SpriteObject::set_pos(sf::Vector2<double> newPos) {
	pos = newPos;
	sprite.setPosition(pos);
}

void SpriteObject::set_angle(double newTheta) {
	theta = newTheta;
	sprite.setRotation(theta);
}

void SpriteObject::set_mirror(bool mir) {
	mirror = mir;
	if (mirror) {
		sprite.setOrigin({sprite.getLocalBounds().width, 0});
		sprite.setScale({-1, 1});
	}
	else {
		sprite.setOrigin({0, 0});
		sprite.setScale({1, 1});
	}
}
