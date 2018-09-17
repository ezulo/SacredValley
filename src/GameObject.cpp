#include "GameObject.h"

GameObject::GameObject() {
}

GameObject::~GameObject() {
	delete orientation;
}

bool GameObject::get_visible() {
	return isVisible;
}

void GameObject::set_visible(bool vis) {
	isVisible = vis;
}

void GameObject::set_physics(bool detectEvent, bool applyPhysics) {
	detectCollisionEvent = detectEvent;
	applyCollisionPhysics = applyPhysics;
}

double GameObject::get_x_pos() {
	return xPos;
}

double GameObject::get_y_pos() {
	return yPos;
}

void GameObject::set_pos(double x, double y) {
	xPos = x;
	yPos = y;
	sprite.setPosition(x, y);
}
