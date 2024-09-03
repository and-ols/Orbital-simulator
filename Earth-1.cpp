/***********************************************************************
 * Source File:
 *    Earth.h : Things to do with the Earth.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about the Earth.
 ************************************************************************/

#include "Earth.h"
#include "uiDraw.h"


/***********************************************
 * DRAW
 * Draws the earth.
***********************************************/
void Earth::draw()
{
   ogstream gout;
   gout.drawEarth(pos, angle);
}
