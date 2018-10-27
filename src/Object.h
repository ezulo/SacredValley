#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

// Object encapsulates any object in game that is
// displayed or interacted with. Object will contain
// object behaviors (e.g. for player character, move
// when arrow key is pressed and animate accordingly)

class Object() {
	public:
		Object(const std::string textureFileName);
		~Object();
		bool get_visible();
		void set_visible(bool vis);
		double get_x_pos();
		double get_y_pos();
		sf::Vector2 get_pos();
		double get_angle();
		bool get_mirror();
		void set_pos(double x, double y);
		void set_pos(sf::Vector2 newPos);
		void set_angle(double newTheta);
		void set_mirror(bool mir);
	private:
		// Metadata
		bool isVisible;
		// Physical characteristics
		double theta;
		bool mirror;
		sf::Vector2 size;
		sf::Vector2 pos;
		// SFML objects
		// Note: handling of below data structs will differ depending on whther
		// the object is static or animated.
		sf::Texture* texture;
		sf::Sprite* sprite;
}

#endif
