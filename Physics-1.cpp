/***********************************************************************
 * Source File:
 *    Physics.h : Things to do with the physics.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about the physics.
 ************************************************************************/

#include "Physics.h"
#include "position.h"
#include "Earth.h"
#include "Satellite.h"
#define _USE_MATH_DEFINES
#include <math.h>

/*********************************************************
* HEIGHT ABOVE THE EARTH
* Calculate the height of the satellite above the Earth.
* The equation is:
*     h = sqrt(x^2 + y^2) - r
*********************************************************/
double heightAboveTheEarth(Position* satellite)
{
   return sqrt((satellite->getMetersX() * satellite->getMetersX()) +
      (satellite->getMetersY() * satellite->getMetersY())) - EARTH_RADIUS;
}

/************************************************************
* DIRECTION OF GRAVITY PULL
* Calculate the direction of the pull of gravity in radians.
* The equation is:
* d = atan(y1 - y2, x1 - x2) (for atan2)
* x1, y1 = Earth position
* x2, y2 = Satellite position
************************************************************/
double getDirectionOfGravityPull(Position* satellite, Position* earth)
{
   return atan2(satellite->getMetersX() - earth->getMetersX(),
      satellite->getMetersY() - earth->getMetersY());
}

/*********************************************************
* COMPUTE DISTANCE
* Calculate the distance of two objects.
* The equation is:
*     h = sqrt(x^2 + y^2) - r1 - r2
*********************************************************/
double computeDistance(Satellite* sat1, Satellite* sat2)
{
   // Get values for computation.
   double radius1 = sat1->getRadius();
   double radius2 = sat2->getRadius();
   Position pos1 = sat1->getPosition();
   Position pos2 = sat2->getPosition();

   // Calculate the distance and return it.
   double distance = sqrt(((pos2.getPixelsX() - pos1.getPixelsX()) * (pos2.getPixelsX()
      - pos1.getPixelsX())) + ((pos2.getPixelsY() - pos1.getPixelsY()) *
         (pos2.getPixelsY() - pos1.getPixelsY())));
   distance = distance - (radius1 + radius2);
   return distance;
}

/***********************************************
 * COMPUTE GRAVITY EQUATION
 * Find the magnitude of acceleration due to gravity at an altitude.
 * The equation is:
 *     gh = g(r / r + h)^2
 ***********************************************/
double getEffectiveGravity(double height)
{
   return SEA_LEVEL_GRAVITY * (EARTH_RADIUS / (EARTH_RADIUS + height))
      * (EARTH_RADIUS / (EARTH_RADIUS + height));
}

/***********************************************
* COMPUTE HORIZONTAL COMPONENT
* Find the horizontal component of a velocity or acceleration.
* The equation is:
*     sin(a) = x / total
* This can be expressed graphically:
*      x
*    +-----
*    |   /
*  y |  / total
*    |a/
*    |/
* INPUT
*     a : angle, in radians
*     total : total velocity or acceleration
* OUTPUT
*     x : the vertical component of the total
***********************************************/
double computeHorizontalComponent(double angle, double speed)
{
   return speed * sin(angle);
}

/***********************************************
* COMPUTE VERTICAL COMPONENT
* Find the vertical component of a velocity or acceleration.
* The equation is:
*     cos(a) = y / total
* This can be expressed graphically:
*      x
*    +-----
*    |   /
*  y |  / total
*    |a/
*    |/
* INPUT
*     a : angle, in radians
*     total : total velocity or acceleration
* OUTPUT
*     y : the vertical component of the total
***********************************************/
double computeVerticalComponent(double angle, double speed)
{
   return speed * cos(angle);
}

/************************************************
* COMPUTE TOTAL COMPONENT
* Given the horizontal and vertical components of
* something (velocity or acceleration), determine
* the total component. To do this, use the Pythagorean Theorem:
*    x^2 + y^2 = t^2
* where:
*      x
*    +-----
*    |   /
*  y |  / total
*    | /
*    |/
* INPUT
*    x : horizontal component
*    y : vertical component
* OUTPUT
*    total : total component
***********************************************/
double computeTotalComponent(double horComp, double vertComp)
{
   return sqrt((horComp * horComp) + (vertComp * vertComp));
}