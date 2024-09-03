/***********************************************
 * Source File:
 *    Velocity : Things to do with velocity.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about velocity.
 **********************************************/

#pragma once
#define INITIAL_VELOCITY     -3100 // m/s

#include <iostream>
#include <cmath>
#include <cassert>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Physics.h"

using namespace std;

class Position;
class TestVelocity;
class Earth;

/***********************************************************
* Velocity
* This will deal with all the velocity for the simulation
**********************************************************/
class Velocity
{
   friend TestVelocity;
private:
   double dx;
   double dy;
public:
   // Constructors
   Velocity() : dx(INITIAL_VELOCITY), dy(0.0) {}
   Velocity(double angle, double speed)
   {
      dx = computeHorizontalComponent(angle, speed);
      dy = computeVerticalComponent(angle, speed);
   }

   // Getters.
   double getDX() { return dx; }
   double getDY() { return dy; }

   // Setters.
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void setDxDy(double dx, double dy) {
      this->dx = dx;
      this->dy = dy;
   }
   void applyAcceleration(double ddx, double ddy, double time);
   double getChangeInX(double ddx, double time)
      { return dx * time + 0.5 * (ddx * (time * time)); }
   double getChangeInY(double ddy, double time)
      { return dy * time + 0.5 * (ddy * (time * time)); }
   void addV(const Velocity& v)
   {
      dx += v.dx;
      dy += v.dy;
   }
   Velocity& operator += (const Velocity& rhs) {
      addV(rhs);
      return *this;
   }
};