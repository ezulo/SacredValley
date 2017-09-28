#include "FrameMgr.h"
#include "frames/GameFrame.h"
#include "frames/GreenCircle.h"

void FrameMgr::init()
{
  GameFrame *init_frame = new GreenCircle();
  push_frame(init_frame);
  return;
}

int FrameMgr::loop()
{
  if (get_current_frame()){ 
    return get_current_frame()->loop();
  }
  return 0;
}

int FrameMgr::transmit_event(Event *event)
{
  if (get_current_frame()){
    return get_current_frame()->event(event);
  }
  return 0;
}

void FrameMgr::push_frame(GameFrame *frame)
{
  frames->push(frame);
  update_frame();
  return;
}

void FrameMgr::pop_frame()
{
  free(frames->pop());
  update_frame();
  return;
}

GameFrame* FrameMgr::get_current_frame()
{
  return currentFrame;
}

FrameMgr::FrameMgr()
{
  init();
}

void FrameMgr::update_frame()
{
  if (frames->top()){
    currentFrame = frames->top();
  } else {
    quit();
  }
}

FrameMgr::~FrameMgr()
{
  free(currentFrame);
}
