#include <iostream>
#include "FrameMgr.h"

/* 
PUBLIC
*/

int FrameMgr::loop()
{
  if (get_current_frame() != NULL){ 
    return get_current_frame()->loop();
  } else {
    return -1;
  }
}

int FrameMgr::transmit_event(sf::Event *event)
{
  if (get_current_frame()){
    return get_current_frame()->event(event);
  }
  return 0;
}

GameFrame* FrameMgr::get_current_frame()
{
  return frames.top();
}

FrameMgr::FrameMgr(sf::RenderWindow* wPtr, InputMgr* iMptr)
{
  gameWindow = wPtr;
  inputMgr = iMptr;
  GameFrame *init_frame = new RedCircle(gameWindow, inputMgr);
  push_frame(init_frame);
}

FrameMgr::~FrameMgr()
{
  //need to empty frames
  purge_frames();
}

/*
PRIVATE
*/

void FrameMgr::purge_frames()
{
  while (!frames.empty()) {
    GameFrame* tmp = frames.top();
    frames.pop();
    delete tmp;
  }
}

void FrameMgr::push_frame(GameFrame *frame)
{
  frames.push(frame);
  return;
}

void FrameMgr::pop_frame()
{
  frames.pop();
  return;
}
