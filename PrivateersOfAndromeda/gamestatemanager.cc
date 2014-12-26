/*******************************************************************************
* File: gamestatemanager.cc
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 22
* Version: 0
* Revised: 2014 DEC 23
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
*******************************************************************************/

#include "gamestatemanager.h"

/*******************************
* Constructors and Destructor */

GameStateManager::GameStateManager(void) {
}
GameStateManager::~GameStateManager(void) {
}

/*******************************
* Methods                    */
//Pop returns the top state of the state stack, and removes it from the stack
GameState GameStateManager::Pop() {
  GameState temp = current_state_.top();
  temp.Unload();
  current_state_.pop();
  current_state_.top().Uncover();
  return temp;
}

//Peek returns the top state of the state stack, and leaves it on the stack
GameState GameStateManager::Peek() {
  return current_state_.top();
}

void GameStateManager::Push(GameState new_state) {
  current_state_.top().Cover();
  new_state.Load();
  current_state_.push(new_state);
}

//Calls the render of all active renderables, from the bottom up
void GameStateManager::Render() {
  for (int i=0; active_renderables_.size(); ++i) { //we draw from the bottom up
    active_renderables_.at(i).Render();
  }
}

//Calls the update of all active renderables, from the top down
void GameStateManager::Update(double elapsed_time_in_ms) {
  for(int i = active_updatable_.size() - 1; i >= 0; --i) {
    active_updatable_.at(i).Update(elapsed_time_in_ms);
  }
}

//CursorPositionFunction is the callback function for GLFW it forwards calls to
//the current active GameState's CursorPositionFunction
//relative to topleft
void GameStateManager::CursorPositionFunction(
    GLFWwindow * window,
    double x_position,  
    double y_position) {
  current_state_.top().CursorPositionFunction (window, x_position, y_position);
}

void GameStateManager::MouseButtonFunction(
    GLFWwindow* window,
    int button,// GLFW_MOUSE_BUTTON_#
    int action, //GLFW_PRESS -or- GLFW_RELEASE.
    int modifers) {
  current_state_.top().MouseButtonFunction(window, button, action, modifers);
}
  
void GameStateManager::ScrollWheelFunction(
    GLFWwindow * window,
    double x_offset,
    double y_offset) {
  current_state_.top().ScrollWheelFunction(window, x_offset, y_offset);
}


void GameStateManager::KeyboardFunction(
    GLFWwindow * window,
    int key,
    int scancode,
    int action,//GLFW_PRESS, GLFW_RELEASE -or- GLFW_REPEAT
    int modifiers) {
  current_state_.top().KeyboardFunction (window,
                                        key,
                                        scancode,
                                        action,
                                        modifiers);
}



