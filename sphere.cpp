#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "sphere.hpp"

using namespace std;

void sphere::draw() {
	glPushMatrix();
	// After physics get calculated move the object to its current position
	
	float x = static_cast<float>(X);
	float y = static_cast<float>(Y);
	float z = static_cast<float>(Z);

	glTranslatef(x,y,z);

	// Sets color of ball
	glColor3f(1.0f, 0.0f, 1.0f);

	//Draws the ball using 
	glutSolidSphere(radius, 10, 10);

	// now we pop the matrix to show we are finished
	glPopMatrix();
}
