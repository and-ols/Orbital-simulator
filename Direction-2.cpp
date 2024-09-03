/***********************************************************************
 * Source File:
 *    Direction.h : Things to do with angles.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about an angle.
 ************************************************************************/

#include "Direction.h"

/***************************************************
 * STANDARDIZE
 * Converts radians to a valid state by increasing
 * or decreasing by 2pi.
***************************************************/
double Direction::standardize(double radians)
{
   while (radians > 2 * M_PI || radians < 0.0)
   {
      // When radians is grater than 2 PI
      if (radians > 2 * M_PI)
         radians -= 2 * M_PI;
      // When it is less than 2 PI
      else if (radians < 0.0)
         radians += 2 * M_PI;
   }
   return radians;
}
