#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameObjectOrientation.h"
using namespace std;

// GameObject encapsulates any object in game that is
// displayed or interacted with. GameObject will contain
// object behaviors (e.g. for player character, move
// when arrow key is pressed and animate accordingly)

class GameObject() {
	public:
		GameObject();
		~GameObject();
		set_visible(bool vis);
		set_physics(bool detectEvent, bool applyPhysics);
	private:
		GameObjectOrientation* orientation;
		bool isVisible;
		bool detectCollisionEvent;
		bool applyCollisionPhysics;
}

#endif
