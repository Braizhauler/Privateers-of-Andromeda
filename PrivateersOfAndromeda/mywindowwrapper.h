/*******************************************************************************
* File: mywindowwrapper.h
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 19
* Version: 0
* Revised: 2014 DEC 21
*
*
* MyWindowWrapper:
* A wrapper for GLFW Window
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
*******************************************************************************/

#ifndef MY_WINDOW_WRAPPER_H_
#define MY_WINDOW_WRAPPER_H_

#include <glfw3.h>

#include "logfile.h"
#include "inputhandler.h"

class MyWindowWrapper {
public:
  //Constructors, and Destructor
	MyWindowWrapper(LogFile& error_log);
	~MyWindowWrapper(void);
  const bool Init(const int width, const int height, const char * title);
  void Terminate (void);

  //Methods
  void ProccessOSEvents();
  void Resize(void);
  void SwapBuffers(void);

  //Accessors and Mutators
	const bool initialized();
	const bool done();

  char const* title();
  void set_title(char * title);

  GLFWwindow * context(void);
private:
  // Member Variables
  LogFile* error_log_;
	GLFWwindow* window_;
	bool initialized_;
	bool finished_;
  int width_;
  int height_;
  char * title_;
};

#endif //MY_WINDOW_WRAPPER_H_