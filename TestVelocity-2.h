/************************************************************************
* Source File:
*    TestVelocity
* Author:
*    Andrew Olson, Michael Darling.
* Summary:
*    Testing the Velocity class with variety of test cases.
************************************************************************/

#pragma once
#include <iostream>
#include <cassert>
#include <set>

using namespace std;

class TestVelocity
{
public:
   void run();

private:
   void test_applyAcceleration_ddxSmall();
   void test_applyAcceleration_ddxBig();
   void test_applyAcceleration_ddySmall();
   void test_applyAcceleration_ddyBig();
   
   // Geters
   void test_getDX();
   void test_getDY();


   // Setters
   void test_setDX();
   void test_setDY();
   void test_getChangeInX_small(); 
   void test_getChangeInX_large();
   void test_getChangeInY_small();
   void test_getChangeInY_large();
};

