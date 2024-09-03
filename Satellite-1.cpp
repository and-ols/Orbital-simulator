/***********************************************************************
 * Source File:
 *    Satellite : Things to do with the satellite.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    Everything we need to know about the satellite.
 ************************************************************************/

#include "Satellite.h"
#include "Physics.h"
#include "Earth.h"
#include "uiInteract.h"
#include "uiDraw.h"

Satellite::Satellite() : position(), v(), dir(), isDead(false)
{
   position.setMetersX(computeHorizontalComponent(0, GEO_DISTANCE));
   position.setMetersY(computeVerticalComponent(0, GEO_DISTANCE));
   isDead = false;
}

Satellite::Satellite(Position* pos, Velocity* velocity, Direction* direction)
{
   position = *pos;
   v = *velocity;
   dir = *direction;
   isDead = false;
}

Satellite::Satellite(double radians, double speed, double distance) : 
   position(), v(radians + M_PI / 2, speed), dir(radians), isDead(false)
{
   position.setMetersX(computeHorizontalComponent(radians, distance));
   position.setMetersY(computeVerticalComponent(radians, distance));
   isDead = false;
}

/***********************************************
  * Move
  * Moves the satellite.
  ***********************************************/
void Satellite::move(Position* earth, const Interface* pUI)
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
}

Projectile::Projectile(Position* pos, Velocity* velocity, Direction* direction) : Satellite(pos, velocity, direction) {
   Velocity launchVelocity(dir.getRadians(), PROJECTILE_SPEED);
   v += launchVelocity;

   // Put it in front of the ship by 19 pixels.
   // position = pivot(pos, 0.0, 19.0, direction.getRadians());

   //cout << "rChange in x: " << v.getDX() << " rChange in y: " << v.getDY() << endl;
   for (int i = 0; i < 3; i++) {
      position.addMetersX(v.getDX() * 75);
      position.addMetersY(v.getDY() * 75);
   }

   // Give it an allowance.
   lifetime = FRAME_RATE;

   radius = 1.0;
}

/***********************************************
 * MOVE
 * Moves the projectile.
 ***********************************************/
void Projectile::move(Position* earth, const Interface* pUI)
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

   // Move the projectile.
   v.applyAcceleration(ddx, ddy, TIME);
   position.addMetersX(v.getChangeInX(ddx, TIME));
   position.addMetersY(v.getChangeInY(ddy, TIME));

   // Update its age and see if it has died.
   lifetime -= 1.3;
   if (lifetime <= 0) {
      kill();
   }
}

/***********************************************
 * DRAW
 * Draws the projectile.
***********************************************/
void Projectile::draw()
{
   ogstream gout;

   // Draws the projectile.
   gout.drawProjectile(position);
}