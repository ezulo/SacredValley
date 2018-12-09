#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H

#include "Object.h"

const std::string DEFAULT_FONT = "arial.ttf"
const int DEFAULT_CHARACTER_SIZE = 11

// A simple object that does not move and is not animated. Pretty much a
// generic container with no additional functionality.
class TextObject : Object {
	public:
		TextObject();
		TextObject(const std::string fontName);
		~TextObject();
		void set_text(const std::string text);
		void set_text_color(int r, int g, int b);
		void set_font(const std::string fontName);
		void set_font_size(int sizeInPixels);
	private:
		sf::Text text;
		sf::Font font;
};

#endif
