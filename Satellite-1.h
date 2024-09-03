/***********************************************************************
 * Header File:
 *    Satellite.h : Things to do with the satellite.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about the satellite.
 ************************************************************************/

#pragma once

#include "position.h"
#include "Velocity.h"
#include "Direction.h"

#include <list>

#define PROJECTILE_SPEED      9000.0

class Physics;
class Earth;
class Interface;
class ogstream;

/***************************************************************
 * SATELLITE
 * Everything to do with the satellites.
 **************************************************************/
class Satellite
{
protected:
   Position position;
   Velocity v;
   Direction dir;
   bool isDead;
   double radius;

public:
   Satellite();
   Satellite(Position* pos, Velocity* velocity, Direction* direction);
   Satellite(double radians, double speed, double distance);
   virtual void move(Position* earth, const Interface* pUI);
   virtual double getRadius() const { return radius; }
   bool getIsDead() { return isDead; }
   Position getPosition() { return position; }
   Velocity getVelocity() { return v; }
   Direction getDirection() { return dir; }
   virtual void rotate(double rate, const Interface* pUI) { dir.rotate(rate); }
   virtual void kill() { isDead = true; }
   virtual void collideWithEarth() { isDead = true; }
   virtual void draw() = 0;
   virtual void destroySelf(list<Satellite*> &satellites) = 0;
};

/***************************************************************
 * PROJECTILE
 * Everything to do with our projectile.
 **************************************************************/
class Projectile : public Satellite
{
private:
   int lifetime;
public:
   Projectile(Position* pos, Velocity* velocity, Direction* direction);
   void move(Position* earth, const Interface* pUI);
   void draw();
   void destroySelf(list<Satellite*>& satellites) { kill(); }
};