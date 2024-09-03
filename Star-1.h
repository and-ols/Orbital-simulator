/***************************************************
 * Header File:
 *    STAR
 * Author:
 *    Andrew Olson, Michael Darling
 * Summary:
 *    Keeps track of everything to do with the star
 *    including the phase and position of the star.
***************************************************/

#include <iostream>
#include "position.h"
#pragma once
using namespace std;

class ogstream;

/********************************************
* STAR
* This class keeps track of everything
* to do with the stars.
*******************************************/
class Star
{
private:
   unsigned char phase;
   Position pt;

public:
   // Constructor.
   Star(const Position& ptUpperRight);

   // Getters.
   Position getPosition() { return this->pt; }
   unsigned char getPhase() { return phase; }

   // Setters.
   void progressPhase() { phase++; }
};