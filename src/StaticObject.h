#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "Object.h"

// A simple object that does not move and is not animated. Pretty much a
// generic container with no additional functionality.
class StaticObject() : Object {
	public:
		StaticObject(const std::string textureFileName)
			: Object(textureFileName);
		~StaticObject();
}

#endif
