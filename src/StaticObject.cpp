#include "StaticObject.h"

StaticObject::StaticObject(const std::string textureFileName) 
	: Object(textureFileName) {
		size = texture.getSize();
		mirror = false;
		theta = 0;
		pos.x = 0;
		pos.y = 0;
}

StaticObject::~StaticObject() {
}
