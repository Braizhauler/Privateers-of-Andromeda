/**********************************************************
* File: inputhandler.h
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 21
* Version: 0
* Revised: 2014 DEC 21
*
* InputHandler:
*   Handles events for Keyboard (and eventually all) input.
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
************************************************************/

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <glfw3.h>

class InputHandler
{
public:
  //Constructors, Init, and Des tructor
  InputHandler(void);
  ~InputHandler(void);
  //Methods
  void HandleEvents(void);
  //Accessors and Mutators
private:
  //Member variables
  GLFWwindow* window_;
};


#endif //INPUT_HANDLER_H