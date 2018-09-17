#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

// GameObject encapsulates any object in game that is
// displayed or interacted with. GameObject will contain
// object behaviors (e.g. for player character, move
// when arrow key is pressed and animate accordingly)

class GameObject() {
	public:
		GameObject();
		~GameObject();
		bool get_visible();
		void set_visible(bool vis);
		void set_physics(bool detectEvent, bool applyPhysics);
		double get_x_pos();
		double get_y_pos();
		void set_pos(double x, double y);
		void set_angle(double theta);
		// Get SFML objects
		sf::Sprite get_sprite();
	private:
		// Metadata
		bool isVisible;
		bool detectCollisionEvent;
		bool applyCollisionPhysics;
		// Physical characteristics
		double xSize;
		double ySize;
		double xPos;
		double yPos;
		double theta;
		bool mirror;
		// SFML objects
		// Note: handling of below data structs will differ depending on whther
		// the object is static or animated.
		sf::Texture texture;
		sf::Sprite sprite;
}

#endif
