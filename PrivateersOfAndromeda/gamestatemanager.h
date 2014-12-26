/*******************************************************************************
* File: gamestatemanager.h
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 22
* Version: 0
* Revised: 2014 DEC 24
*
* GameStateManager:
*   A file for keeping track of current state, and redirecting calls to
*   all active game states/logic.
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
*******************************************************************************/

#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include <stack>
#include <vector>
#include <glfw3.h>

#include "gamestate.h"
#include "renderable.h"
#include "updateable.h"

class GameStateManager {
public:
  //Constructors and Destructor
  GameStateManager(void);
  ~GameStateManager(void);
  //Methods
  GameState Pop();
  GameState Peek();
  void Push(GameState new_state);

  void Render();
  void Update(double elapsed_time_in_ms);

  void CursorPositionFunction(GLFWwindow * window,
                        double x_position,  //relative to left
                        double y_position); //relative to top

  void MouseButtonFunction(GLFWwindow* window,
                           int button,// GLFW_MOUSE_BUTTON_#
                           int action, //GLFW_PRESS -or- GLFW_RELEASE.
                           int modifers);
  
  void ScrollWheelFunction(GLFWwindow * window,
                           double x_offset,
                           double y_offset);

  void KeyboardFunction(GLFWwindow * window,
                        int key,
                        int scancode,
                        int action,//GLFW_PRESS, GLFW_RELEASE -or- GLFW_REPEAT
                        int modifiers);

  //Accessors and Mutators
private:
  //Member Variables
  std::stack<GameState> current_state_;
  std::vector<Renderable> active_renderables_;
  std::vector<Updateable> active_updatable_;
};


#endif //GAME_STATE_MANAGER_H