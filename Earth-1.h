/***********************************************************************
 * Header File:
 *    Earth : Things to do with the Earth.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about the Earth.
 ************************************************************************/

#pragma once
#include "position.h"

#define EARTH_RADIUS       6378000 // Meters

class ogstream;

/***************************************************************
 * EARTH
 * Takes care of the Earth.
 **************************************************************/
class Earth
{
private:
   Position pos;
   double angle = 0.0;
public:
   Earth() {}
   void rotate(double rate) { angle += rate; }
   void draw();
   Position* getPosition() { return &pos; }
};