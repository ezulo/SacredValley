#include <EventDispatcher.h>
#include <Event.h>

int EventDispatcher::send_event(Event event, GameFrame *frame)
{
  int status = frame->event(Event);
  if (status) {
    return 0;
  } else {
    return 1;
  }
}

EventDispatcher::EventDispatcher
{
  
}
