/***********************************************************************
 * Source File:
 *    Velocity.h : The things to do with the velocity.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about velocity.
 ************************************************************************/

#include "Velocity.h"
#include "position.h"
#include "Earth.h"
#include <cassert>

using namespace std;

/***********************************************
 * APPLY ACCELERATION
 * Update velocity based on acceleration.
 * dx = dx0 + ddx * time
 * dy = dy0 + ddy * time
 ***********************************************/
void Velocity::applyAcceleration(double ddx, double ddy, double time)
{
   this->dx += ddx * time;
   this->dy += ddy * time;
}

