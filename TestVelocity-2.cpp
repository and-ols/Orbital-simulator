/***********************************************************************
* Source File:
*    TestVelocity.h
* Author:
*    Andrew Olson, Michael Darling.
* Summary:
*    Testing the Velocity class with variety of test cases.
************************************************************************/

#include "TestVelocity.h"
#include "Velocity.h"
#include "position.h"

/*****************************************************************
 * RUN
 * Runs all the unit tests
 ****************************************************************/
void TestVelocity::run()
{
   test_applyAcceleration_ddxSmall();
   test_applyAcceleration_ddxBig();
   test_applyAcceleration_ddySmall();
   test_applyAcceleration_ddyBig();
   
   // Getters
   test_getDX();
   test_getDY();

   // Setters
   test_setDX();
   test_setDY();
   test_getChangeInX_small();
   test_getChangeInX_large();
   test_getChangeInY_small();
   test_getChangeInY_large();
}

void TestVelocity::test_applyAcceleration_ddxSmall()
{
   // setup.
   Velocity v;
   v.dx = 300.0;
   v.dy = 300.0;
   //exercise.
   v.applyAcceleration(50, 0, 1);
   // verify.
   assert(v.dx == 350);
   assert(v.dy == 300);
   // teardown.
}

void TestVelocity::test_applyAcceleration_ddxBig()
{
   // setup.
   Velocity v;
   v.dx = 300.0;
   v.dy = 300.0;
   //exercise.
   v.applyAcceleration(100, 0, 1);
   // verify.
   assert(v.dx == 400);
   assert(v.dy == 300);
   // teardown.
}

void TestVelocity::test_applyAcceleration_ddySmall()
{
   // setup.
   Velocity v;
   v.dx = 300.0;
   v.dy = 300.0;
   //exercise.
   v.applyAcceleration(0, 50, 1);
   // verify.
   assert(v.dx == 300);
   assert(v.dy == 350);
   // teardown.
}

void TestVelocity::test_applyAcceleration_ddyBig()
{
   // setup.
   Velocity v;
   v.dx = 300.0;
   v.dy = 300.0;
   //exercise.
   v.applyAcceleration(0, 100, 1);
   // verify.
   assert(v.dx == 300);
   assert(v.dy == 400);
   // teardown.
}

void TestVelocity::test_getDX()
{
   // setup.
   Velocity v;
   v.dx = 30.0;
   v.dy = 0.0;
   //exercise.
   double dx = v.getDX();
   // verify.
   assert(dx == 30.0);
   // teardown.
}

void TestVelocity::test_getDY()
{
   // setup.
   Velocity v;
   v.dx = 0.0;
   v.dy = 30.0;
   //exercise.
   double dy = v.getDY();

   // verify.
   assert(dy == 30.0);

   // teardown.
}

void TestVelocity::test_setDX()
{
   // setup.
   Velocity v;
   v.dx = 30.0;
   v.dy = 30.0;

   //exercise.
   v.setDX(50.0);
   
   // verify.
   assert(v.dx == 50.0);
   assert(v.dy == 30.0);
   
   // teardown.
}

void TestVelocity::test_setDY()
{
   // setup.
   Velocity v;
   v.dx = 30.0;
   v.dy = 30.0;
   
   //exercise.
   v.setDY(50.0);
   
   // verify.
   assert(v.dx == 30.0);
   assert(v.dy == 50.0);
   
   // teardown.
}

void TestVelocity::test_getChangeInX_small()
{
   // setup.
   Velocity v;
   v.dx = 50.0;
   v.dy = 50.0;
   double ddx = 100.0;
   double ddy = 0.0;

   //exercise.
   double changeInX = v.getChangeInX(ddx, 1);

   // verify.
   assert(changeInX == 100.0);

   // teardown.
}

void TestVelocity::test_getChangeInX_large()
{
   // setup.
   Velocity v;
   v.dx = 50.0;
   v.dy = 50.0;
   double ddx = 1000.0;
   double ddy = 0.0;

   //exercise.
   double changeInX = v.getChangeInX(ddx, 1);

   // verify.
   assert(changeInX == 550.0);

   // teardown.
}

void TestVelocity::test_getChangeInY_small()
{
   // setup.
   Velocity v;
   v.dx = 50.0;
   v.dy = 50.0;
   double ddx = 0.0;
   double ddy = 100.0;

   //exercise.
   double changeInY = v.getChangeInY(ddy, 1);

   // verify.
   assert(changeInY == 100.0);

   // teardown.
}

void TestVelocity::test_getChangeInY_large()
{  
   // setup.
   Velocity v;
   v.dx = 50.0;
   v.dy = 50.0;
   double ddx = 0.0;
   double ddy = 1000.0;

   //exercise.
   double changeInY = v.getChangeInY(ddy, 1);

   // verify.
   assert(changeInY == 550.0);

   // teardown.
}