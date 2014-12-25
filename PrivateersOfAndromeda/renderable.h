/**********************************************************
* File: renderable.h
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 24
* Version: 0
* Revised: 2014 DEC 24
*
* Renderable:
*   Virtual class for game states that require a update.
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
************************************************************/

#ifndef RENDERABLE_H
#define RENDERABLE_H

class Renderable {
public:
  //Constructors and Destructor
  virtual ~Renderable(void);

  virtual void Render(void) = 0;
};

#endif //RENDERABLE_H