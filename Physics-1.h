/***********************************************************************
 * Header File:
 *    Satellite.h : Things to do with physics functions.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about physics functions.
 ************************************************************************/

#pragma once
#define SEA_LEVEL_GRAVITY -9.80665 // m/s^2
#define GEO_DISTANCE      42164000 // How far in order to orbit in meters
#define FRAME_RATE           80 // Frames/sec
#define ROTATIONS_FRAME  1/1800 // Rotations/sec
#define TIME                 48 // Seconds/frame

class Position;
class Earth;
class Satellite;

double heightAboveTheEarth(Position* satellite);
double getDirectionOfGravityPull(Position* satellite, Position* earth);
double computeDistance(Satellite* pos1, Satellite* pos2);

double getEffectiveGravity(double height);
double computeHorizontalComponent(double angle, double speed);
double computeVerticalComponent(double angle, double speed);
double computeTotalComponent(double horComp, double vertComp);