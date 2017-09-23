#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState{
  public:
    virtual void init();
    virtual void handle_events();
    virtual void update();
    virtual void draw();
    void change_state(Game* game, GameState state) {
      game->change_state(state);
    }
    
  protected:
    GameState() {}
}

#endif
