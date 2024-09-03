/***********************************************************************
* Source File:
*    TestPart.h
* Author:
*    Andrew Olson, Michael Darling.
* Summary:
*    Testing the part class with variety of test cases.
************************************************************************/

#include "TestPart.h"
#include "Whole.h"
#include "Physics.h"

using namespace std;

/*****************************************************************
 * RUN
 * Runs all the unit tests
 ****************************************************************/
void TestPart::run()
{
   test_tooFar();
   test_close();
}

void TestPart::test_tooFar()
{
   // setup.
   Position* crPos = new Position(0.0, 0.0);
   Position* clPos = new Position(0.0, 20000.0);
   Velocity* baseVel = new Velocity();
   Direction* baseDir = new Direction();
   CrewDragonRight* cR = new CrewDragonRight(crPos, baseVel, baseDir, 0.0);
   CrewDragonLeft* cL = new CrewDragonLeft(clPos, baseVel, baseDir, 0.0);
   
   //exercise.
   double distance = computeDistance(cR, cL);

   // verify.
   cout << distance << endl;
   assert(distance > 0.0);

   // teardown.
}

void TestPart::test_close()
{
   // setup.
   Position* crPos = new Position(0.0, 0.0);
   Position* clPos = new Position(0.0, 20.0);
   Velocity* baseVel = new Velocity();
   Direction* baseDir = new Direction();
   CrewDragonRight* cR = new CrewDragonRight(crPos, baseVel, baseDir, 0.0);
   CrewDragonLeft* cL = new CrewDragonLeft(clPos, baseVel, baseDir, 0.0);

   //exercise.
   double distance = computeDistance(cR, cL);

   // verify.
   cout << distance << endl;
   assert(distance < 0.0);

   // teardown.
}
