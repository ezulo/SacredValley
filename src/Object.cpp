#include "Object.h"

Object::Object() {
}

Object::~Object() {
}

bool Object::get_visible() {
	return isVisible;
}


double Object::get_x_pos() {
	return pos.x;
}

double Object::get_y_pos() {
	return pos.y;
}

sf::Vector2<double> Object::get_pos() {
	return pos;
}

double Object::get_angle() {
	return theta;
}

bool Object::get_mirror() {
	return mirror;
}

void Object::set_visible(bool vis) {
	isVisible = vis;
}

