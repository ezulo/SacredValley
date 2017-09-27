#ifndef EVENT_H
#define EVENT_H
#include <string>

Event::Event(string message)
{
  msg = message; 
}

string Event::get_event()
{
  return msg;
}

Event::~Event()
{
}

#endif
