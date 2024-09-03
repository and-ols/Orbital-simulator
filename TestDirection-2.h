/************************************************************************
* Source File:
*    TestDirection
* Author:
*    Andrew Olson, Michael Darling.
* Summary:
*    Testing the Direction class with variety of test cases.
************************************************************************/

#pragma once
#include <iostream>
#include <cassert>
#include <cmath>

/***************************************************************
 * TEST DIRECTION
 * All of our test cases for direction.
 **************************************************************/
class TestDirection
{
public:
   void run();

private:

   // Setters
   void test_setRadians_normal();
   void test_setRadians_lessThanPi();
   void test_setRadians_moreThanPi();
   void test_setDegrees_normal();
   void test_setDegrees_lessThan0degrees();
   void test_setDegrees_moreThan360degrees();
   void test_setDXDY_0degrees();
   void test_setDXDY_45degrees();
   void test_setDXDY_90degrees();

   // Set direction absolutely.
   void test_setUp();
   void test_setDown();
   void test_setLeft();
   void test_setRight();

   // Rotate
   void test_degreesToRadians();
   void test_radiansToDegrees();
   void test_rotate_small();
   void test_rotate_big();

   // Getters
   void test_getRadians();
   void test_getDegrees();
   void test_getDX_0degrees();
   void test_getDX_45degrees();
   void test_getDX_90degrees();
   void test_getDY_0degrees();
   void test_getDY_45degrees();
   void test_getDY_90degrees();
};