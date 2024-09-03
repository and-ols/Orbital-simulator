/*************************************
 * Source File:
 *    STAR.h
 * Author:
 *    Andrew Olson, Michael Darling
 * Summary:
 *    This files tracks everything to
 *    do with the star class.
 ************************************/

#include "Star.h"
#include "uiDraw.h"

/************************************************************************
* CONSTRUCTOR
* Create a new star with a random phase and point.
************************************************************************/
Star::Star(const Position& ptUpperRight)
{
   phase = rand() % 256;
   pt.setPixelsX(random(-(int)ptUpperRight.getPixelsX(),(int)ptUpperRight.getPixelsX()));
   pt.setPixelsY(random(-(int)ptUpperRight.getPixelsY(),(int)ptUpperRight.getPixelsY()));
}