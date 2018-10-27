#include "Object.h"

Object::Object(const std::string& textureFileName) {
	texture = new Texture();
	if (texture.loadFromFile(textureFileName)) {
		sprite = new Sprite(texture);
	}
	else {
		throw std::runtime_error(
			"Error from Object constructor: texture not found."
		);
	}
	isVisible = true;
}

Object::~Object() {
	delete texture;
	delete sprite;
}

bool Object::get_visible() {
	return isVisible;
}

void Object::set_visible(bool vis) {
	isVisible = vis;
}

double Object::get_x_pos() {
	return pos.x;
}

double Object::get_y_pos() {
	return pos.y;
}

sf::Vector2 Object::get_pos() {
	return pos;
}

double Object::get_angle() {
	return theta;
}

bool Object::get_mirror() {
	return mirror;
}

void Object::set_pos(double x, double y) {
	pos.x = x;
	pos.y = y;
	sprite.setPosition(pos);
}

void Object::set_pos(sf::Vector2 newPos) {
	pos = newPos;
	sprite.setPosition(pos);
}

void Object::set_angle(double newTheta) {
	theta = newTheta;
	sprite.setRotation(theta);
}

void Object::set_mirror(bool mir) {
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
