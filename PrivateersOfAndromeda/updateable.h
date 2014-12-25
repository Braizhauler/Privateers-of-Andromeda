/**********************************************************
* File: updatable.h
* Author: Greg Howlett (GregTHowlett@Gmail.com)
* Created: 2014 DEC 24
* Version: 0
* Revised: 2014 DEC 24
*
* Updatable:
*   Virtual class for game states that require a update.
*
* © [2014] Dwarfholm.com
* All Rights Reserved.
************************************************************/

#ifndef UPDATEABLE_H
#define UPDATEABLE_H

class Updateable {
public:
  //Constructors and Destructor
  virtual ~Updateable(void);
  virtual void Update(double time_in_ms) = 0;
};

#endif //UPDATEABLE_H