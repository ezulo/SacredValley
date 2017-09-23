#include <states/GameState.h>
#include <stack>

class StateMgr {
  public:
    void change_state(GameState *state);
    void push_state(GameState *state);
    GameState* pop_state();
    StateMgr();
  private:
    unique_ptr<stack<GameState*>> states;
}
