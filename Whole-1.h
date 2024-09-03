/***********************************************************************
 * Header File:
 *    Whole.h : Things to do with whole objects.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about whole objects.
 ************************************************************************/

#pragma once

#include "Satellite.h"
#include "uiDraw.h"

#define THRUST   2.0

class Direction;
class uiInteract;

/***********************************************************
* Whole
* Everything to do with satellites what are whole.
***********************************************************/
class Whole : public Satellite
{
public:
   Whole() : Satellite() {}
   Whole(Position* pos, Velocity* velocity, Direction* dir) : Satellite(pos, velocity, dir) {}
   Whole(double radians, double speed, double distance) : Satellite(radians, speed, distance) {}
};

/***********************************************************
* Hubble
* Everything for the Hubble satellite.
***********************************************************/
class Hubble : public Whole
{
private:
public:
   Hubble() : Whole(M_PI, INITIAL_VELOCITY, GEO_DISTANCE) { radius = 10.0; }
   void draw();
   void destroySelf(list<Satellite*>& satellites);
};

/***********************************************************
* DreamChaser
* Everything for the DreamChaser satellite.
***********************************************************/
class DreamChaser : public Whole
{
private:
   bool thrustActive = false;
public:
   DreamChaser();
   void move(Position* earth, const Interface* pUI);
   void rotate(double rate, const Interface* pUI);
   void draw();
   void kill() {}
   void destroySelf(list<Satellite*>& satellites) { return; }
};

/***********************************************************
* Sputnik
* Everything for the Sputnik satellite.
***********************************************************/
class Sputnik : public Whole
{
public:
   Sputnik() : Whole(M_PI / 3, 3377.87, 42164000) { radius = 4.0; }
   void draw();
   void destroySelf(list<Satellite*>& satellites);
};

/***********************************************************
* GPS
* Everything for the GPS satellite.
***********************************************************/
class GPS : public Whole
{
public:
   GPS(double radians) : Whole(radians, -3880.0, 26560000.0) { radius = 12.0; }
   void draw();
   void destroySelf(list<Satellite*>& satellites);
};

/***********************************************************
* CrewDragon
* Everything for the CrewDragon satellite.
***********************************************************/
class CrewDragon : public Whole
{
private:
public:
   CrewDragon();
   void draw();
   void destroySelf(list<Satellite*>& satellites);
};

/***********************************************************
* Starlink
* Everything for the Starlink satellite.
***********************************************************/
class Starlink : public Whole
{
private:
public:
   Starlink();
   void draw();
   void destroySelf(list<Satellite*>& satellites);
};

class TestPart;

/***************************************************************
 * PART
 * Everything to do with the the parts of the satellites
 **************************************************************/
class Part : public Satellite
{
   friend TestPart;
protected:
   int fragCount;
public:
   Part(Position* position, Velocity* v, Direction* dir, double angleOffset);
   virtual void destroySelf(list<Satellite*>& satellites);
};

/***************************************************************
 * CREWDRAGON RIGHT
 * Everything to do with the various pieces of CrewDragon.
 **************************************************************/
class CrewDragonRight : public Part
{
protected:
   int fragCount = 2;
public:
   CrewDragonRight(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 6.0; }
   void draw() { ogstream gout; gout.drawCrewDragonRight(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * CREWDRAGON LEFT
 * Everything to do with the various pieces of CrewDragon.
 **************************************************************/
class CrewDragonLeft : public Part
{
protected:
   int fragCount = 2;
public:
   CrewDragonLeft(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 6.0; }
   void draw() { ogstream gout; gout.drawCrewDragonLeft(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * CREWDRAGON CENTER
 * Everything to do with the various pieces of CrewDragon.
 **************************************************************/
class CrewDragonCenter : public Part
{
protected:
   int fragCount = 4;
public:
   CrewDragonCenter(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 6.0; }
   void draw() { ogstream gout; gout.drawCrewDragonCenter(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * GPS LEFT
 * Everything to do with the various pieces of GPS.
 **************************************************************/
class GPSLeft : public Part
{
protected:
   int fragCount = 3;
public:
   GPSLeft(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 8.0; }
   void draw() { ogstream gout; gout.drawGPSLeft(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * GPS RIGHT
 * Everything to do with the various pieces of GPS.
 **************************************************************/
class GPSRight : public Part
{
protected:
   int fragCount = 3;
public:
   GPSRight(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 8.0; }
   void draw() { ogstream gout; gout.drawGPSRight(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * GPS CENTER
 * Everything to do with the various pieces of GPS.
 **************************************************************/
class GPSCenter : public Part
{
protected:
   int fragCount = 3;
public:
   GPSCenter(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 7.0; }
   void draw() { ogstream gout; gout.drawGPSCenter(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * HUBBLE COMPUTER
 * Everything to do with the various pieces of Hubble.
 **************************************************************/
class HubbleComputer : public Part
{
protected:
   int fragCount = 2;
public:
   HubbleComputer(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 7.0; }
   void draw() { ogstream gout; gout.drawHubbleComputer(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * HUBBLE TELESCOPE
 * Everything to do with the various pieces of Hubble.
 **************************************************************/
class HubbleTelescope : public Part
{
protected:
   int fragCount = 3;
public:
   HubbleTelescope(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 10.0; }
   void draw() { ogstream gout; gout.drawHubbleTelescope(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * HUBBLE LEFT
 * Everything to do with the various pieces of Hubble.
 **************************************************************/
class HubbleLeft : public Part
{
protected:
   int fragCount = 2;
public:
   HubbleLeft(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 8.0; }
   void draw() { ogstream gout; gout.drawHubbleLeft(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * HUBBLE RIGHT
 * Everything to do with the various pieces of Hubble.
 **************************************************************/
class HubbleRight : public Part
{
protected:
   int fragCount = 2;
public:
   HubbleRight(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 8.0; }
   void draw() { ogstream gout; gout.drawHubbleRight(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * STARLINK BODY
 * Everything to do with the various pieces of StarLink.
 **************************************************************/
class StarlinkBody : public Part
{
protected:
   int fragCount = 3;
public:
   StarlinkBody(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 2.0; }
   void draw() { ogstream gout; gout.drawStarlinkBody(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * STARLINK ARRAY
 * Everything to do with the various pieces of StarLink.
 **************************************************************/
class StarlinkArray : public Part
{
protected:
   int fragCount = 3;
public:
   StarlinkArray(Position* position, Velocity* v, Direction* dir, double angleOffset) : Part(position, v, dir, angleOffset) { radius = 4.0; }
   void draw() { ogstream gout; gout.drawStarlinkArray(getPosition(), dir.getRadians()); }
};

/***************************************************************
 * FRAGMENT
 * Everything to do with the various satellite fragments.
 **************************************************************/
class Fragment : public Part
{
private:
   double lifetime = random(50.0,100.0);
public:
   Fragment(Position* position, Velocity* v, Direction* dir, double angleOffset);
   void draw() { ogstream gout; gout.drawFragment(getPosition(), dir.getRadians()); }
   void move(Position* earth, const Interface* pUI);
   void kill() {}
   void expire() { isDead = true; }
   void destroySelf(list<Satellite*>& satellites) { return; }
};