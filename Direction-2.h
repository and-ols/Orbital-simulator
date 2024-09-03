/***********************************************************************
 * Header File:
 *    Direction : Things to do with angles.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about an angle.
 ************************************************************************/

#pragma once

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

class TestDirection;

/***************************************************************
 * DIRECTION
 * Takes care of all directional calculations. 
 * 
 * IMPORTANT NOTE:
 * 0° is North for reference, rotating clockwise.
 **************************************************************/
class Direction
{
   friend TestDirection;
private:
   double radians = 0.0;

public:
   // Constructors.
   Direction() {};
   Direction(double rhs) : radians(rhs) {}

   // Setters.
   double standardize(double radians);
   void setRadians(double rhs_radians) { radians = standardize(rhs_radians); }
   void setDegrees(double rhs_degrees) 
      { radians = standardize(rhs_degrees * M_PI / 180); }
   void setDown() { radians = M_PI / 2; }
   void setUp() { radians = M_PI * 3 / 2; }
   void setRight() { radians = 0.0; }
   void setLeft() { radians = M_PI; }
   void reverse() { radians = -radians; }
   void rotate(double rate) { radians += rate; }
   void setAngleFromComponents(double dx, double dy) 
      { radians = atan(dx / dy); }
   void setDxDy(double dx, double dy)
   {
      radians = atan2(dx, dy);
   }
   double degreesToRadians(double degrees) { return degrees * M_PI / 180; }
   double radiansToDegrees(double radians) { return radians * 180 / M_PI; }

   // Getters.
   double getRadians() { return radians; }
   double getDegrees() { return radians * 180 / M_PI; }
   double getAngleFromComponents(double dx, double dy)
      { return atan(dx / dy); }
   double getDX(double speed) { return speed * cos(radians); }
   double getDY(double speed) {return speed * sin(radians); }
};