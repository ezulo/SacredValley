#include "Event.h"

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

