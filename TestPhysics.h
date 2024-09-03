/***********************************************************************
* Header File:
*    TestPart
* Author:
*    Andrew Olson, Michael Darling.
* Summary:
*    Testing the physics class with variety of test cases.
************************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

/***************************************************************
 * TEST PHYSICS
 * All the test cases for physics.
 **************************************************************/
class TestPhysics
{
public:
   void run();
private:
   void test_heightAboveTheEarth_Small();
   void test_heightAboveTheEarth_Large();
   void test_directionOfGravityPull_0degrees();
   void test_directionOfGravityPull_90degrees();
   void test_directionOfGravityPull_30degrees();
   void test_directionOfGravityPull_135degrees();
   void test_computeHorizontalComponent_0degrees();
   void test_computeHorizontalComponent_45degrees();
   void test_computeHorizontalComponent_90degrees();
   void test_computeVerticalComponent_0degrees();
   void test_computeVerticalComponent_45degrees();
   void test_computeVerticalComponent_90degrees();
};

