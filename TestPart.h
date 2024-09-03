/***********************************************************************
* Header File:
*    TestPart
* Author:
*    Andrew Olson, Michael Darling.
* Summary:
*    Testing the part class with variety of test cases.
************************************************************************/

#pragma once
#include <cassert>

class Part;
class Physics;

/***************************************************************
 * TEST PART
 * All of the test casses for parts.
 **************************************************************/
class TestPart
{
public:
   void run();

private:
   void test_tooFar();
   void test_close();
};

