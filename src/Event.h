#ifndef EVENT_H
#define EVENT_H

#include <string>

using namespace std;

class Event
{
  public:
    Event(string message);
    string get_event();
  private:
    string msg;
    ~Event();
};

#endif
