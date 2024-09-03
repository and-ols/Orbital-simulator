/***********************************************************************
* Source File:
*    TestPhysics.h
* Author:
*    Andrew Olson, Michael Darling.
* Summary:
*    Testing the Physics class with variety of test cases.
************************************************************************/

#include "TestPhysics.h"
#include "Physics.h"
#include <cassert>
#include "position.h"
#include <iostream>

using namespace std;

/*****************************************************************
 * RUN
 * Runs all the unit tests
 ****************************************************************/
void TestPhysics::run()
{
   test_heightAboveTheEarth_Small();
   test_heightAboveTheEarth_Large();
   test_directionOfGravityPull_0degrees();
   test_directionOfGravityPull_90degrees();
   test_directionOfGravityPull_30degrees();
   test_directionOfGravityPull_135degrees();
   test_computeHorizontalComponent_0degrees();
   test_computeHorizontalComponent_45degrees();
   test_computeHorizontalComponent_90degrees();
   test_computeVerticalComponent_0degrees();
   test_computeVerticalComponent_45degrees();
   test_computeVerticalComponent_90degrees();
}

void TestPhysics::test_heightAboveTheEarth_Small()
{
   // setup.
   Position milleniumFalcon(7000000.0, 0.0);
   Position* p = &milleniumFalcon;
   //exercise.
   double height = heightAboveTheEarth(p);
   // verify.
   assert(height == 622000.0);
   // teardown.
}

void TestPhysics::test_heightAboveTheEarth_Large()
{
   // setup.
   Position milleniumFalcon(70000000.0, 0.0);
   Position* p = &milleniumFalcon;
   //exercise.
   double height = heightAboveTheEarth(p);
   // verify.
   assert(height == 63622000.0);
   // teardown.
}

void TestPhysics::test_directionOfGravityPull_0degrees()
{
   // setup.
   Position milleniumFalcon(0.0, 200.0);
   Position* ptRebels = &milleniumFalcon;
   Position deathStar(0.0, 0.0);
   Position* ptEmpire = &deathStar;
   //exercise.
   double direction = getDirectionOfGravityPull(ptRebels, ptEmpire);
   // verify.
   assert(direction == 0.0);
   // teardown.
}

void TestPhysics::test_directionOfGravityPull_90degrees()
{
   // setup.
   Position milleniumFalcon(200.0, 0.0);
   Position* ptRebels = &milleniumFalcon;
   Position deathStar(0.0, 0.0);
   Position* ptEmpire = &deathStar;
   //exercise.
   double direction = getDirectionOfGravityPull(ptRebels, ptEmpire);
   // verify.
   assert(direction == M_PI / 2);
   // teardown.
}

void TestPhysics::test_directionOfGravityPull_30degrees()
{
   // setup.
   Position milleniumFalcon(230.0, 400.0);
   Position* ptRebels = &milleniumFalcon;
   Position deathStar(0.0, 0.0);
   Position* ptEmpire = &deathStar;
   //exercise.
   double direction = getDirectionOfGravityPull(ptRebels, ptEmpire);
   // verify.
   assert(direction > M_PI / 6 - 0.1 && direction < M_PI / 6);
   // teardown.
}

void TestPhysics::test_directionOfGravityPull_135degrees()
{
   // setup.
   Position milleniumFalcon(200.0, -200.0);
   Position* ptRebels = &milleniumFalcon;
   Position deathStar(0.0, 0.0);
   Position* ptEmpire = &deathStar;
   //exercise.
   double direction = getDirectionOfGravityPull(ptRebels, ptEmpire);
   // verify.
   assert(direction == M_PI * 3 / 4);
   // teardown.
}

void TestPhysics::test_computeHorizontalComponent_0degrees()
{
   // setup.
   double angle = 0.0;
   double speed = 50.0;
   //exercise.
   double hComp = computeHorizontalComponent(angle, speed);
   // verify.
   assert(hComp == 0.0);
   // teardown.
}

void TestPhysics::test_computeHorizontalComponent_45degrees()
{
   // setup.
   double angle = M_PI / 4;
   double speed = 50.0;
   //exercise.
   double hComp = computeHorizontalComponent(angle, speed);
   // verify.
   assert(hComp > 35.355 && hComp < 35.356);
   // teardown.
}

void TestPhysics::test_computeHorizontalComponent_90degrees()
{
   // setup.
   double angle = M_PI / 2;
   double speed = 50.0;
   //exercise.
   double hComp = computeHorizontalComponent(angle, speed);
   // verify.
   assert(hComp == 50.0);
   // teardown.
}

void TestPhysics::test_computeVerticalComponent_0degrees()
{
   // setup.
   double angle = 0.0;
   double speed = 50.0;
   //exercise.
   double vComp = computeVerticalComponent(angle, speed);
   // verify.
   assert(vComp == 50.0);
   // teardown.
}

void TestPhysics::test_computeVerticalComponent_45degrees()
{
   // setup.
   double angle = M_PI / 4;
   double speed = 50.0;
   //exercise.
   double vComp = computeVerticalComponent(angle, speed);
   // verify.
   assert(vComp > 35.355 && vComp < 35.356);
   // teardown.
}

void TestPhysics::test_computeVerticalComponent_90degrees()
{
   // setup.
   double angle = M_PI / 2;
   double speed = 50.0;
   //exercise.
   double vComp = computeVerticalComponent(angle, speed);
   // verify.
   assert(vComp > 0.0 && vComp < 0.1);
   // teardown.
}