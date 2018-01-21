#include "Overworld.h"

//Public methods
int handle_events() {}

int load_assets() {}

int draw() {}

int loop() {
  handle_events();
  draw();
  return -1;
}

int event(sf::Event* event) {
  return -1;
}
