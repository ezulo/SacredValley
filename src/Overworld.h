#ifndef OVERWORLD_H 
#define OVERWORLD_H 

#include "GameState.h"

using namespace std;

class Overworld : public GameState {
  public:
    int load_assets();
    int loop();
    int receive_event(sf::Event* event);
    Overworld();
    ~Overworld();
  protected:
    void draw();
    float xCamPosition, yCamPosition;
    bool flux;
    int red;
};

#endif
