/**********************************************************
* File: gamestatemanager.cc
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 22
* Version: 0
* Revised: 2014 DEC 23
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
************************************************************/

#include "gamestatemanager.h"

/*******************************
* Constructors and Destructor */

GameStateManager::GameStateManager(void) {
}
GameStateManager::~GameStateManager(void) {
}

/*******************************
* Methods                    */
void GameStateManager::Draw() {
  active_state_->Draw();
}

//CursorPositionFunction is the callback function for GLFW it forwards calls to
//the current active GameState's CursorPositionFunction
//relative to topleft
void GameStateManager::CursorPositionFunction(
    GLFWwindow * window,
    double x_position,  
    double y_position) {
  active_state_->CursorPositionFunction(window, x_position, y_position);
}

void GameStateManager::MouseButtonFunction(
    GLFWwindow* window,
    int button,// GLFW_MOUSE_BUTTON_#
    int action, //GLFW_PRESS -or- GLFW_RELEASE.
    int modifers) {
  active_state_->MouseButtonFunction(window, button, action, modifers);
}
  
void GameStateManager::ScrollWheelFunction(
    GLFWwindow * window,
    double x_offset,
    double y_offset) {
  active_state_->ScrollWheelFunction(window, x_offset, y_offset);
}


void GameStateManager::KeyboardFunction(
    GLFWwindow * window,
    int key,
    int scancode,
    int action,//GLFW_PRESS, GLFW_RELEASE -or- GLFW_REPEAT
    int modifiers) {
  active_state_->KeyboardFunction(window, key, scancode, action, modifiers);
}

void GameStateManager::ChangeState(GameState* new_state)  {
  active_state_->ExitState();
  active_state_=new_state;
  active_state_->EnterState();
}

/*******************************
* Accessors and Mutators      */
  GameState * active_state();
