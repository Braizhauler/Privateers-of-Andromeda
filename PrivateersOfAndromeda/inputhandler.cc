/**********************************************************
* File: inputhandler.cc
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 21
* Version: 0
* Revised: 2014 DEC 21
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
************************************************************/

#include "inputhandler.h"

//Constructor
//Initializes all private members of InputHandler
InputHandler::InputHandler(void) {
}

//Init
//Additional parts of the constructor that are complicated or could fail. 
bool InputHandler::Init(void) {
  return false;
}

//Destructor
//Cleans up all loose pointers, etc.
InputHandler::~InputHandler(void) {
}

void InputHandler::HandleEvents() {
  glfwGetKey(window_, GLFW_KEY_ESCAPE );
}

/*******************************
* Constructors and Destructor */
/*******************************
* Methods                     */

/*******************************
* Accessors and Mutators      */