#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "camera.hpp"
#include "sphere.hpp"
#include "physics.hpp"
#include "scene.hpp"
void scene::initGL() {
	time = 0.0;
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glShadeModel(GL_SMOOTH); 

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	GLfloat lightPosition[] = {0.0f, 10.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void scene::display(int sphereamnt) {
	// Clears the color buffer
	
	sphere b;
	sphere c(0.0, 0.1, 0.0, 0.01);
	sphere d(0.1, 0.0, 0.0, 0.01);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*TODO: get cmaera stuff working soon*/
	
	//gluLookAt(65.0f, 10.5f, 30.0f, 200, 200, 200, 0, 1, 0);

	GLfloat matAmbient[] = {1.0f,1.0f,1.0f,1.0f};
	GLfloat matDiffuse[] = {1.0f,1.0f,1.0f,1.0f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	
	//TODO: get a better way of working with vectors like this or use an array instead
		
		s.push_back(b);
		s.push_back(c);
		s.push_back(d);
		for(int i = 0; i < 3; i++) {
			s.at(i).draw();
		}
		
	glutSwapBuffers();
}

void scene::update() {
	//TODO: figure out where the SEG FAULT is
	physics P;
	P.SetSphere(s);
	P.Step(dt);
	// P.Collision();	
	
	for(int i = 0; i < 3; i++) {
		s.at(i).draw();
	}	

	glutPostRedisplay();
}

void scene::timer() {
	dt = static_cast<float>(glutGet(GLUT_ELAPSED_TIME) - time);
	time = static_cast<float>(glutGet(GLUT_ELAPSED_TIME) + time);
}

