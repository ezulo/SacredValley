#include "GameObject.h"

GameObject::GameObject() {
	orientation = new GameObjectOrientation();
}

GameObject::~GameObject() {
	delete orientation;
}

GameObject::set_visible(bool vis) {
	isVisible = vis;
}

GameObject::set_physics(bool detectEvent, bool applyPhysics) {
	detectCollisionEvent = detectEvent;
	applyCollisionPhysics = applyPhysics;
}
