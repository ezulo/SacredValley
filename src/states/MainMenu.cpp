#include <iostream>
#include "MainMenu.h"

void MainMenu::handle_events(){
  float mult = 0.7071067;
  switch (inputMgr->getInput("dir")){
    case -1:
      xVelo = 0;
      yVelo = 0;
      break;
    case 0:
      xVelo = DEF_VELO;
      yVelo = 0;
      break;
    case 1:
      xVelo = DEF_VELO * mult;
      yVelo = -DEF_VELO * mult;
      break;
    case 2:
      xVelo = 0;
      yVelo = -DEF_VELO;
      break;
    case 3:
      xVelo = -DEF_VELO * mult;
      yVelo = -DEF_VELO * mult;
      break;
    case 4:
      xVelo = -DEF_VELO;
      yVelo = 0;
      break;
    case 5:
      xVelo = -DEF_VELO * mult;
      yVelo = DEF_VELO * mult;
      break;
    case 6:
      xVelo = 0;
      yVelo = DEF_VELO;
      break;
    case 7:
      xVelo = DEF_VELO * mult;
      yVelo = DEF_VELO * mult;
      break;
    default:
      std::cout << "ERROR PARSING DIRECTION" << endl;
      xVelo = 0;
      yVelo = 0;
      break;
  }
  return;
}

void MainMenu::load_assets() {
  //for this we need a Font object
  //EDIT THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  load_asset_font
}

void MainMenu::draw()
{

  //create glow effect
  if (red >= 255) {
    flux = false;
  } else if (red <= 126) {
    flux = true;
  }
  if (flux) {
    red++;
  } else {
    red--;
  }
  shape.setFillColor(sf::Color(red, 0, 0));

  //move sphere
  shape.move(xVelo, yVelo * -1);
  
  game_window->clear();
  game_window->draw(shape);
  game_window->display();
  return;
}

int MainMenu::loop()
{
  inputMgr->listen();
  handle_events();
  draw();
  return 0;
}

int MainMenu::event(sf::Event* event)
{
  //no events handled here, class is just for testing
  return 0;
}

MainMenu::MainMenu(sf::RenderWindow* wptr, InputMgr* iMptr):GameState(wptr, iMptr)
{
  //initilize option boxes
  optionBoxes[0] = sf::Text("New Game");
  optionBoxes[1] = sf::Text("Load Game");
  optionBoxes[2] = sf::Text("Settings");
  optionBoxes[3] = sf::Text("Quit");
  shape.setFillColor(sf::Color(255, 0, 0));
  xVelo = 0;
  yVelo = 0;
}

MainMenu::~MainMenu()
{
}
