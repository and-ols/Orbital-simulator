/***********************************************************************
* Source File:
*    TestDirection.h
* Author:
*    Andrew Olson, Michael Darling.
* Summary:
*    Testing the Direction class with variety of test cases.
************************************************************************/

#include "TestDirection.h"
#include "Direction.h"

using namespace std;

/*****************************************************************
 * RUN
 * Runs all the unit tests
 ****************************************************************/
void TestDirection::run()
{
   // Setters
   test_setRadians_normal();
   test_setRadians_lessThanPi();
   test_setRadians_moreThanPi();
   test_setDegrees_normal();
   test_setDegrees_lessThan0degrees();
   test_setDegrees_moreThan360degrees();
   test_setDXDY_0degrees();
   test_setDXDY_45degrees();
   test_setDXDY_90degrees();

   // Set direction absolutely.
   test_setUp();
   test_setDown();
   test_setLeft();
   test_setRight();

   // Rotate
   test_degreesToRadians();
   test_radiansToDegrees();
   test_rotate_small();
   test_rotate_big();

   // Getters
   test_getRadians();
   test_getDegrees();
   test_getDX_0degrees();
   test_getDX_45degrees();
   test_getDX_90degrees();
   test_getDY_0degrees();
   test_getDY_45degrees();
   test_getDY_90degrees();
}

void TestDirection::test_setRadians_normal()
{
   // setup.
   Direction d;
   d.radians = 1.0;
   double radians = 0.5;
   //exercise.
   d.setRadians(radians);
   // verify.
   assert(d.radians == 0.5);
   // teardown.
}

void TestDirection::test_setRadians_lessThanPi()
{
   // setup.
   Direction d;
   d.radians = 1.0;
   double radians = - M_PI / 2;
   //exercise.
   d.setRadians(radians);
   // verify.
   assert(d.radians == M_PI * 3 / 2);
   // teardown.
}

void TestDirection::test_setRadians_moreThanPi()
{
   // setup.
   Direction d;
   d.radians = 1.0;
   double radians = M_PI * 5 / 2;
   //exercise.
   d.setRadians(radians);
   // verify.
   assert(d.radians == M_PI / 2);
   // teardown.
}

void TestDirection::test_setDegrees_normal()
{
   Direction d;
   d.radians = 1.0;
   double degrees = 90.0;

   //exercise.
   d.setDegrees(degrees);

   // verify.
   assert(d.radians == M_PI / 2);

   // teardown.
}

void TestDirection::test_setDegrees_lessThan0degrees()
{
   Direction d;
   d.radians = 1.0;
   double degrees = -90.0;

   //exercise.
   d.setDegrees(degrees);

   // verify.
   assert(d.radians == M_PI * 3 / 2);

   // teardown.
}

void TestDirection::test_setDegrees_moreThan360degrees()
{
   Direction d;
   d.radians = 1.0;
   double degrees = 405.0;

   //exercise.
   d.setDegrees(degrees);

   // verify.
   assert(d.radians > 0.785397 && d.radians < 0.785399);

   // teardown.
}

void TestDirection::test_setDXDY_0degrees()
{
   // setup.
   Direction d;
   double dx = 0.0;
   double dy = 90.0;
   //exercise.
   d.setDxDy(dx, dy);
   // verify.
   assert(d.radians == 0.0);
   // teardown.
}

void TestDirection::test_setDXDY_45degrees()
{
   // setup.
   Direction d;
   double dx = 45.0;
   double dy = 45.0;
   //exercise.
   d.setDxDy(dx, dy);
   // verify.
   assert(d.radians == M_PI / 4);
   // teardown.
}

void TestDirection::test_setDXDY_90degrees()
{
   // setup.
   Direction d;
   double dx = 90.0;
   double dy = 0.0;
   //exercise.
   d.setDxDy(dx, dy);
   // verify.
   assert(d.radians == M_PI / 2);
   // teardown.
}

void TestDirection::test_setUp()
{
   // setup.
   Direction d;
   d.radians = 0.0;
   //exercise.
   d.setUp();
   // verify.
   assert(d.radians == (M_PI * 3 / 2));
   // teardown.
}

void TestDirection::test_setDown()
{
   // setup.
   Direction d;
   d.radians = 0.0;
   //exercise.
   d.setDown();
   // verify.
   assert(d.radians == (M_PI / 2));
   // teardown.
}

void TestDirection::test_setLeft()
{
   // setup.
   Direction d;
   d.radians = 0.0;
   //exercise.
   d.setLeft();
   // verify.
   assert(d.radians == M_PI);
   // teardown.
}

void TestDirection::test_setRight()
{
   // setup.
   Direction d;
   d.radians = 30.0;
   //exercise.
   d.setRight();
   // verify.
   assert(d.radians == 0.0);
   // teardown.
}

void TestDirection::test_degreesToRadians()
{
   // setup.
   Direction d;
   double degrees = 90.0;
   //exercise.
   double radians = d.degreesToRadians(degrees);
   // verify.
   assert(radians == M_PI / 2);
   // teardown.
}

void TestDirection::test_radiansToDegrees()
{
   // setup.
   Direction d;
   double radians = M_PI / 2;
   //exercise.
   double degrees = d.radiansToDegrees(radians);
   // verify.
   assert(degrees == 90.0);
   // teardown.
}

void TestDirection::test_rotate_small()
{
   // setup.
   Direction d;
   d.radians = 1.0;
   double radians = 0.1;
   //exercise.
   d.rotate(radians);

   // verify.
   assert(d.radians == 1.1);
   // teardown.
}

void TestDirection::test_rotate_big()
{
   // setup.
   Direction d;
   d.radians = 1.0;
   double radians = 5.0;
   //exercise.
   d.rotate(radians);
   // verify.
   assert(d.radians == 6.0);
   // teardown.
}

void TestDirection::test_getRadians()
{
   // setup.
   Direction d;
   d.radians = 1.0;
   //exercise.
   double radians = 1.0;
   // verify.
   assert(d.radians == 1.0);
   // teardown.
}

void TestDirection::test_getDegrees()
{
   // setup.
   Direction d;
   d.radians = 1.0;
   //exercise.
   double degrees = d.getDegrees();
   // verify.
   assert(degrees > 57.2 && degrees < 57.3);
   // teardown.
}

void TestDirection::test_getDX_0degrees()
{
   // setup.
   Direction d;
   d.radians = 0.0;
   double speed = 20.0;
   // exercise.
   double dx = d.getDX(speed);
   // verify.
   assert(dx == 20.0);
   //teardown.
}

void TestDirection::test_getDX_45degrees()
{
   // setup.
   Direction d;
   d.radians = M_PI / 4;
   double speed = 20.0;
   // exercise.
   double dx = d.getDX(speed);
   // verify.
   assert(dx > 14.141 && dx < 14.143);
   //teardown.
}

void TestDirection::test_getDX_90degrees()
{
   // setup.
   Direction d;
   d.radians = M_PI / 2;
   double speed = 20.0;
   // exercise.
   double dx = d.getDX(speed);
   // verify.
   //cout << dx << endl;
   assert(dx > -0.1 && dx < 0.1);
   //teardown.
}

void TestDirection::test_getDY_0degrees()
{
   // setup.
   Direction d;
   d.radians = 0.0;
   double speed = 20.0;
   // exercise.
   double dy = d.getDY(speed);
   // verify.
   assert(dy == 0.0);
   //teardown.
}

void TestDirection::test_getDY_45degrees()
{
   // setup.
   Direction d;
   d.radians = M_PI / 4;
   double speed = 20.0;
   // exercise.
   double dy = d.getDY(speed);
   // verify.
   assert(dy > 14.141 && dy < 14.143);
   //teardown.
}

void TestDirection::test_getDY_90degrees()
{
   // setup.
   Direction d;
   d.radians = M_PI / 2;
   double speed = 20.0;
   // exercise.
   double dy = d.getDY(speed);
   // verify.
   assert(dy == 20.0);
   //teardown.
}