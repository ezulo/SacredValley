#ifndef STATICSPRITEOBJECT_H
#define STATICSPRITEOBJECT_H

#include "SpriteObject.h"

// A simple object that does not move and is not animated. Pretty much a
// generic container with no additional functionality.
class StaticSpriteObject : SpriteObject {
	public:
		StaticSpriteObject(const std::string textureFileName);
		~StaticSpriteObject();
};

#endif
