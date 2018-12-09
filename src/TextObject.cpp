#include "TextObject.h"

sf::Text create_text_object(sf::Font font, int fontSize = DEFAULT_CHARACTER_SIZE) {
	sf::Text newText; 
	newText.setFont(font);
	newText.setString("");
	newText.setCharacterSize(fontSize);
	return newText;
}

TextObject::TextObject() {
	if (!font.loadFromFile(DEFAULT_FONT)) {
		throw std::runtime_error(
			"Error from TextObject constructor: font not found."
		);
	}
	create_text_object(font);
}

TextObject::TextObject(const std::string fontName) {
	if (!font.loadFromFile(fontName) {
		throw std::runtime_error(
			"Error from TextObject constructor: font not found."
		);
	}
	create_text_object(font);
}

void set_text
