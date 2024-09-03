/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Michael and Andrew
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "TestVelocity.h"
#include "TestDirection.h"
#include "TestPhysics.h"
#include <iostream>
#include "Test.h"

using namespace std;

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestDirection().run();
   cout << "Direction Test Cases have passed." << endl;
   TestVelocity().run();
   cout << "Velocity Test Cases have passed." << endl;
   TestPhysics().run();
   cout << "Physics Test Cases have passed." << endl;
}