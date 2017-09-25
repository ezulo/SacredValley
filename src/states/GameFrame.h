#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include<queue>

class GameFrame{
  public:
    virtual void init();
    virtual void loop();
    virtual int  event();
    virtual void draw();
    void change_frame(Game* game, GameFrame frame) {
      game->change_frame(frame);
    }
    
  protected:
    queue<char*> 
    GameFrame() {}
}

#endif
