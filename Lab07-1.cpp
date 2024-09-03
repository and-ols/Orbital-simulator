/*************************************************************
 * 1. Name:
 *      Michael and Andrew
 * 2. Assignment Name:
 *      Lab 13: Orbit Final Submission
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      
 * 5. How long did it take for you to complete the assignment?
 *      
 *****************************************************************/

#include <cassert>      // for ASSERT
#include <list>
#include <vector>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "Velocity.h"
#include "Physics.h"
#include "Earth.h"
#include "Whole.h"
#include "Star.h"
#include "TestPart.h"
#include "test.h"

#define FRAME_RATE           80 // Frames/sec
#define ROTATIONS_FRAME  1/1800 // Rotations/sec
#define TIME                 48 // Seconds of sim time

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulation
{
private:
   list<Satellite*> satellites;
   DreamChaser dreamchaser;
   Velocity vHubble;
   Position ptUpperRight;
   Earth earth;
   vector<Star> stars;      // The stars

public:
   Simulation(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {

      // Make the satellites.
      Sputnik* ptSputnik = new Sputnik();
      Hubble* ptHubble = new Hubble();
      CrewDragon* ptCrewdragon = new CrewDragon();
      Starlink* ptStarlink = new Starlink();
      DreamChaser* ship = new DreamChaser();

      // Add them to the list.
      satellites.push_back(ship);
      satellites.push_back(ptSputnik);
      satellites.push_back(ptHubble);
      satellites.push_back(ptCrewdragon);
      satellites.push_back(ptStarlink);

      // Make all the GPS Satellites.
      double gpsAngle = 0.0;
      for (int i = 0; i < 6; i++) {
         satellites.push_back(new GPS(gpsAngle));
         gpsAngle += M_PI / 3;
      }

      // Make the stars and add them to the vector.
      for (int i = 0; i < 500; i++)
      {
         Star newStar(ptUpperRight);
         stars.push_back(newStar);
      }
   }

   /***********************************************
   * ROTATE OBJECTS
   * Rotate the Earth and each satellite.
   ***********************************************/
   void rotateObjects(const Interface* pUI) {
      // Rotate the earth.
      earth.rotate(-0.004);
      for (Satellite* sat : satellites) {
         sat->rotate(0.02, pUI);
      }
   }

   /***********************************************
   * MOVE OBJECTS
   * Move each satellite and check for crashes.
   ***********************************************/
   void moveObjects(const Interface* pUI) {
      for (auto it = satellites.begin(); it != satellites.end(); it++) {
         (*it)->move(earth.getPosition(), pUI);
      }

      // Check for crashing.
      for (auto it = satellites.begin(); it != satellites.end(); it++) {

         // ...into other satellites.
         for (auto it2 = satellites.begin(); it2 != satellites.end(); it2++) {
            if (it != it2) {

               // If the two satellites are close enough, break them.
               if (computeDistance(*it, *it2) < 0.0) {
                  (*it)->kill();
                  (*it2)->kill();
               }
            }
         }

         // ...into the Earth.
         if (heightAboveTheEarth(&(*it)->getPosition()) <= 0.0) {
            (*it)->collideWithEarth();
         }

         // ...off into the void.
         if ((*it)->getPosition().getMetersX() > ptUpperRight.getMetersX() ||
            (*it)->getPosition().getMetersX() < -ptUpperRight.getMetersX() ||
            (*it)->getPosition().getMetersY() > ptUpperRight.getMetersY() ||
            (*it)->getPosition().getMetersY() < -ptUpperRight.getMetersX()) {
            (*it)->kill();
         }
      }

      // Go through each satellite and remove the dead ones.
      for (auto it = satellites.begin(); it != satellites.end();) {
         if ((*it)->getIsDead()) {
            (*it)->destroySelf(satellites);
            delete* it;
            it = satellites.erase(it);
         }
         else
         {
            it++;
         }
      }

      // Fire new projectiles.
      if (pUI->isSpace()) {
         Position* pos = &(*satellites.begin())->getPosition();
         Velocity* velo = &(*satellites.begin())->getVelocity();
         Direction* dir = &(*satellites.begin())->getDirection();
         Projectile* ptProjectile = new Projectile(pos, velo, dir);
         satellites.push_back(ptProjectile);
      }
   }

   /***********************************************
   * DRAW OBJECTS
   * This takes care of drawing all objects 
   * (such as satellites, and stars).
   ***********************************************/
   void drawObjects() {
      Position pt;
      ogstream gout(pt);

      // draw satellites
      for (Satellite* sat : satellites)
         sat->draw();

      // phase and draw stars.
      for (auto& star : stars)
      {
         gout.drawStar(star.getPosition(), star.getPhase());
         star.progressPhase();
      }

      // draw the earth
      earth.draw();
   }
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   Simulation* pSimulation = (Simulation*)p;

   pSimulation->rotateObjects(pUI);
   pSimulation->moveObjects(pUI);
   pSimulation->drawObjects();
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulation sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim);


   return 0;
}
