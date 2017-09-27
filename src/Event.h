#include "Event.h"

using namespace std;

class Event
{
  public:
    Event(string message);
    string get_event();
  private:
    string msg;
    ~Event();
}
