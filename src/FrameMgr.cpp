#include <frames/GameFrame.h>
#include <FrameMgr.h>
#include <GreenCircle.h>
#include <stack>

void FrameMgr::init()
{
  //do some setup stuff
 GameFrame *init_frame = new GreenCircle();
 push_frame(init_frame);
 update_frame();
}

int FrameMgr::loop()
{
  if (currentFrame)
  {
    return currentFrame->loop();
  } else {
    return 1;
  }
}

int transmit_event(Event *event)
{
  if(currentFrame) {
    return currentFrame->event(event);
  } else {
    return 1;
  }
}

void FrameMgr::update_frame()
{
  currentFrame = frames->top();
  return;
}

void FrameMgr::push_frame(GameFrame *frame)
{
  frames->push(frame);
  update_frame();
  return;
}

void pop_frame()
{
  frames->pop();
  update_frame();
  return;
}

GameFrame* FrameMgr::get_current_frame()
{
  return currentFrame;
}

FrameMgr::FrameMgr()
{
  //allocate data members 
}
