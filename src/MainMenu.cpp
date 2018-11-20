#include <iostream>
#include "MainMenu.h"

//probably shouldn't be using global vars
const std::string HEADER = "Project Sacred Valley (working title)";
const std::string MENU_PROMPTS[4] = {
  "New Game",
  "Load Game",
  "Settings",
  "Credits"
};

int MainMenu::handle_events(){
  //for now we want to just change selection state
  if (inputMgr->get_input("dir_down", 1)) {
    selection = (selection + 1) % 4;
  }
  if (inputMgr->get_input("dir_up", 1)) {
    selection = (selection - 1) % 4;    
  }
  if (selection == -1)
    selection = 3;
  //simple action: position the cursor according to selection state
  //TO ADD: PLAY A SOUND
  cursor.setPosition(80.0, 191.0 + (selection * 50)); 
  //user input handled here (not yet though)
  //some int should be returned for what input was received
  if (inputMgr->get_input("x", 1)) {
    return -2;
  }
  if (inputMgr->get_input("z", 1)) {
    std::cout << "Input Z Received" << endl;
    return selection;
  }
  return -1;
}

int MainMenu::load_assets() {
  if (font.loadFromFile("./resource/fonts/arial.ttf")) {
    //need to figure out what to do if resource can't be loaded
    //send signal to Game instance to stop?
    //need higher level event listener
    //set to a default?
    gameHeader.setFont(font);
    gameHeader.setString(HEADER);
    gameHeader.setCharacterSize(24);
    gameHeader.setFillColor(sf::Color(255, 255, 255));
    for (int i = 0; i < 4; i++) {
      optionBoxes[i].setFont(font);
      optionBoxes[i].setString(MENU_PROMPTS[i]);
      optionBoxes[i].setCharacterSize(18);
      optionBoxes[i].setFillColor(sf::Color(255, 255, 255));
    }
    //fonts and sizes are set...
    //set positions
    gameHeader.setPosition(80.0, 100.0);
    optionBoxes[0].setPosition(100.0, 200.0);
    optionBoxes[1].setPosition(100.0, 250.0);
    optionBoxes[2].setPosition(100.0, 300.0);
    optionBoxes[3].setPosition(100.0, 350.0);
    cursor.setPosition(80.0, 200.0);
    cursor.setRotation(90.0);
  }
  else {
    std::cout << "Font could not be loaded" << endl;
  }
  return -1;
}

int MainMenu::draw()
{
  //draw everything
  gameWindow->clear();
  gameWindow->draw(cursor);
  gameWindow->draw(gameHeader);
  for (int i = 0; i < 4; i++) {
    gameWindow->draw(optionBoxes[i]);
  } 
  gameWindow->display();
  return -1;
}

int MainMenu::loop()
{
  inputMgr->listen();
  int menu_selected = handle_events();
  draw();
  return menu_selected;
}

int MainMenu::event(sf::Event* event)
{
  return -1;
}

GameState* MainMenu::resolve_transition(int code)
{
  GameState* state;
  switch(code) {
    case 0:
      state = new Overworld(gameWindow, inputMgr, resourceMgr); 
      break;
    default:
      //state mgr responsible for handling this
      std::cout << "Transition unknown, defaulting to current state" << endl;
      state = this;
      break;
  }
  return state;
}

MainMenu::MainMenu(sf::RenderWindow* wptr, InputMgr* iMptr, ResourceMgr* rMptr):GameState(wptr, iMptr, rMptr)
{
  font = sf::Font();
  //initialize cursor
  cursor = sf::CircleShape(20.f, 3);
  //initialize selection key states
  selection = 0;
  load_assets();
}

MainMenu::~MainMenu()
{
}
