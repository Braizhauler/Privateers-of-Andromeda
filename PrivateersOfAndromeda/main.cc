/*******************************************************************************
* filename: main.cc
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 16
* Version: 0
* Revised: 2014 DEC 21
*
* � [2014] Dwarfholm.com
* All Rights Reserved.
*******************************************************************************/
#ifndef PRIVATEERS_OF_ANDROMEDA_CC
#define PRIVATEERS_OF_ANDROMEDA_CC

//hides console window in windows
#pragma comment (linker, "/subsystem:windows /entry:mainCRTStartup") 

#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include "logfile.h"
#include "mywindowwrapper.h"
#include "gamestatemanager.h"


int main (int num_of_arugments, char * argument_list[])  {
  
  LogFile error_log("privateers.log",LogLevel::LOG_ERROR);
  // Initialise GLFW
  if( !glfwInit() )
  {
    fprintf( stderr, "Failed to initialize GLFW\n" );
    return -1;
  }
  
  //Use OpenGL version 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  //error if we use depricated OpenGL
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  //Anti Aliasing x4
  glfwWindowHint(GLFW_SAMPLES, 4); 

  MyWindowWrapper window(error_log);

  window.Init( 640, 480, "Privateers of Andromeda");

  // Initialize GLEW
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "GLEW not sticky enough, Privateers fell apart\n");
    return -1;
  }

  // Set Background to Dark Gray
  glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

  GameStateManager state_manager;


  do {  
    window.ProccessOSEvents();
    // Set the background to the clear color
    glClear(GL_COLOR_BUFFER_BIT);
    // Swap buffers
    window.SwapBuffers();

  } while(!window.done() && window.initialized());
    //glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS
  window.Terminate();

  return 0;

}

#endif // PRIVATEERS_OF_ANDROMEDA_CC