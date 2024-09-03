/***********************************************************************
 * Source File:
 *    Whole.h : Things to do with whole objects.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about whole objects.
 ************************************************************************/

#include "Whole.h"
#include "uiInteract.h"

/***********************************************************
* Draw (Hubble)
* Draws the Hubble satellite.
***********************************************************/
void Hubble::draw()
{
   ogstream gout;
   gout.drawHubble(getPosition(), dir.getRadians());
}

/*******************************************************
 * DESTROY SELF
 * Splits itself into small fragments and hubble parts.
*******************************************************/
void Hubble::destroySelf(list<Satellite*>& satellites)
{
   // Break into 4 pieces, no fragments.
   HubbleTelescope* hubbleTelescope = new HubbleTelescope(&position, &v, &dir, -M_PI / 6);
   HubbleComputer* hubbleComputer = new HubbleComputer(&position, &v, &dir, -M_PI / 3);
   HubbleLeft* hubbleLeft = new HubbleLeft(&position, &v, &dir, M_PI / 3);
   HubbleRight* hubbleRight = new HubbleRight(&position, &v, &dir, M_PI / 6);
   satellites.push_back(hubbleTelescope);
   satellites.push_back(hubbleComputer);
   satellites.push_back(hubbleLeft);
   satellites.push_back(hubbleRight);
}

/***********************************************************
* Draw (Sputnik)
* Draws the Sputnik satellite.
***********************************************************/
void Sputnik::draw()
{
   ogstream gout;
   gout.drawSputnik(getPosition(), dir.getRadians());
}

void Sputnik::destroySelf(list<Satellite*>& satellites)
{
   Fragment* frag1 = new Fragment(&position, &v, &dir, -M_PI / 6);
   Fragment* frag2 = new Fragment(&position, &v, &dir, -M_PI / 3);
   Fragment* frag3 = new Fragment(&position, &v, &dir, M_PI / 3);
   Fragment* frag4 = new Fragment(&position, &v, &dir, M_PI / 6);
   satellites.push_back(frag1);
   satellites.push_back(frag2);
   satellites.push_back(frag3);
   satellites.push_back(frag4);
}

/***********************************************************
* Draw (GPS)
* Draws the GPS satellite.
***********************************************************/
void GPS::draw()
{
   ogstream gout;
   gout.drawGPS(getPosition(), dir.getRadians());
}

/*******************************************************
 * DESTROY SELF
 * Splits itself into small fragments and gps parts.
*******************************************************/
void GPS::destroySelf(list<Satellite*>& satellites)
{
   // 3 pieces, 2 fragments.
   GPSCenter* gpsCenter = new GPSCenter(&position, &v, &dir, 0.0);
   GPSLeft* gpsLeft = new GPSLeft(&position, &v, &dir, -M_PI/3);
   GPSRight* gpsRight = new GPSRight(&position, &v, &dir, M_PI/3);
   Fragment* frag1 = new Fragment(&position, &v, &dir, -M_PI/6);
   Fragment* frag2 = new Fragment(&position, &v, &dir, M_PI/6);
   satellites.push_back(gpsCenter);
   satellites.push_back(gpsLeft);
   satellites.push_back(gpsRight);
   satellites.push_back(frag1);
   satellites.push_back(frag2);
}

DreamChaser::DreamChaser() : Whole(M_PI, 0, GEO_DISTANCE)
{
   position.setPixelsX(-450.0);
   position.setPixelsY(450.0);
   radius = 10.0;
}

/*******************************************************
 * MOVE
 * Moves the dreamchaser, but with user input.
*******************************************************/
void DreamChaser::move(Position* earth, const Interface* pUI)
{
   // Get current angle of the satellite in respect to the Earth in radians.
   double satelliteAngle = position.getAngleFromComponents();

   // Get the current height of the satellite above the Earth.
   double satelliteHeight = heightAboveTheEarth(&position);

   // Get acceleration due to gravity and the angle at which it is pulling.
   double gravity = getEffectiveGravity(satelliteHeight);
   double gravityAngle = getDirectionOfGravityPull(&position, earth);

   // Get the different parts of gravity.
   double ddx = computeHorizontalComponent(gravityAngle, gravity);
   double ddy = computeVerticalComponent(gravityAngle, gravity);

   // Check for thrust and apply.
   if (pUI->isUp()) {
      ddx += computeHorizontalComponent(dir.getRadians(), THRUST);
      ddy += computeVerticalComponent(dir.getRadians(), THRUST);
      thrustActive = true;
   }
   else {
      thrustActive = false;
   }

   // Applies the acceleration.
   v.applyAcceleration(ddx, ddy, TIME);

   // Applies the velocity to the acceleration.
   position.addMetersX(v.getChangeInX(ddx, TIME));
   position.addMetersY(v.getChangeInY(ddy, TIME));
}

/*******************************************************
 * ROTATE
 * Rotates the dreamchaser based on user input.
*******************************************************/
void DreamChaser::rotate(double rate, const Interface* pUI)
{
   if(pUI->isLeft())
      dir.rotate(-0.1);
   else if (pUI->isRight())
      dir.rotate(0.1);
}

/***********************************************************
* Draw (DreamChaser)
* Draws the DreamChaser ship.
***********************************************************/
void DreamChaser::draw()
{
   ogstream gout;
   gout.drawShip(getPosition(), dir.getRadians(), thrustActive);
}

CrewDragon::CrewDragon() : Whole(0.0, -7900.0, 8000000.0) { 
   radius = 7.0;
}

/***********************************************************
* Draw (CrewDragon)
* Draws the CrewDragon satellite.
***********************************************************/
void CrewDragon::draw()
{
   ogstream gout;
   gout.drawCrewDragon(getPosition(), dir.getRadians());
}

/***********************************************************
 * DESTROY SELF
 * Splits itself into small fragments and crewdragon parts.
***********************************************************/
void CrewDragon::destroySelf(list<Satellite*>& satellites)
{
   // 3 pieces, 2 fragments.
   CrewDragonCenter* crewDragonCenter = new CrewDragonCenter(&position, &v, &dir, 0.0);
   CrewDragonRight* crewDragonRight = new CrewDragonRight(&position, &v, &dir, -M_PI / 3);
   CrewDragonLeft* crewDragonLeft = new CrewDragonLeft(&position, &v, &dir, M_PI / 3);
   Fragment* frag1 = new Fragment(&position, &v, &dir, -M_PI / 6);
   Fragment* frag2 = new Fragment(&position, &v, &dir, M_PI / 6);
   satellites.push_back(crewDragonCenter);
   satellites.push_back(crewDragonRight);
   satellites.push_back(crewDragonLeft);
   satellites.push_back(frag1);
   satellites.push_back(frag2);
}

Starlink::Starlink() : Whole(M_PI, 5800.0, -13020000.0) { 
   radius = 6.0;
}

/***********************************************************
* Draw (Starlink)
* Draws the Starlink satellite.
***********************************************************/
void Starlink::draw()
{
   ogstream gout;
   gout.drawStarlink(getPosition(), dir.getRadians());
}

/*******************************************************
 * DESTROY SELF
 * Splits itself into small fragments and Starlink parts.
*******************************************************/
void Starlink::destroySelf(list<Satellite*>& satellites)
{
   // 2 pieces, 2 fragments.
   StarlinkBody* starlinkBody = new StarlinkBody(&position, &v, &dir, -M_PI / 3);
   StarlinkArray* starlinkArray = new StarlinkArray(&position, &v, &dir, M_PI / 3);
   Fragment* frag1 = new Fragment(&position, &v, &dir, -M_PI / 6);
   Fragment* frag2 = new Fragment(&position, &v, &dir, M_PI / 6);
   satellites.push_back(starlinkBody);
   satellites.push_back(starlinkArray);
   satellites.push_back(frag1);
   satellites.push_back(frag2);
}

Part::Part(Position* pos, Velocity* velocity, Direction* direction, double angleOffset) :
   Satellite(pos, velocity, direction)
{
   dir.setRadians(dir.getRadians() + angleOffset);
   double speed = computeTotalComponent(v.getDX(), v.getDY());
   Velocity newV(dir.getRadians(), speed);
   v += newV;
   // Move yaself.
   for (int i = 0; i < 2; i++) {
      position.addPixelsX(computeHorizontalComponent(dir.getRadians(), 16));
      position.addPixelsY(computeHorizontalComponent(dir.getRadians(), 16));
   }
}

/*******************************************************
 * DESTROY SELF
 * Splits itself into small fragments.
*******************************************************/
void Part::destroySelf(list<Satellite*>& satellites)
{
   for (int i = 0; i < fragCount; i++) {
      Fragment* ptFrag = new Fragment(&position, &v, &dir, 0.0);
      satellites.push_back(ptFrag);
   }
}

Fragment::Fragment(Position* position, Velocity* velocity, Direction* dir, double angleOffset) : Part(position, velocity, dir, angleOffset)
{
   Velocity newV(dir->getRadians(), random(5000,9000));
   this->v += newV;
   radius = 2.0;
}

/*******************************************************
 * MOVE
 * Moves the fragments
*******************************************************/
void Fragment::move(Position* earth, const Interface* pUI)
{
   // Get current angle of the satellite in respect to the Earth in radians.
   double satelliteAngle = position.getAngleFromComponents();

   // Get the current height of the satellite above the Earth.
   double satelliteHeight = heightAboveTheEarth(&position);

   // Get acceleration due to gravity and the angle at which it is pulling.
   double gravity = getEffectiveGravity(satelliteHeight);
   double gravityAngle = getDirectionOfGravityPull(&position, earth);

   // Get the different parts of gravity.
   double ddx = computeHorizontalComponent(gravityAngle, gravity);
   double ddy = computeVerticalComponent(gravityAngle, gravity);

   // Applies the acceleration.
   v.applyAcceleration(ddx, ddy, TIME);

   // Applies the velocity to the acceleration.
   position.addMetersX(v.getChangeInX(ddx, TIME));
   position.addMetersY(v.getChangeInY(ddy, TIME));

   // Update its age and see if it has died.
   lifetime -= 1.3;
   if (lifetime <= 0) {
      expire();
   }
}