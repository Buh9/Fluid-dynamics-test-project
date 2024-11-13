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
	glEnaable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	GLfloat lightPosition[] = {0.0f, 10.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	s.reserve(100) //TODO: change to custom number later 
}

void scene::display(int sphereamnt) {
	// Clears the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPHT_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*TODO: get cmaera stuff working soon*/
	
	gluLookAt(65.0f, 10.5f, 30.0f, 400, 400, 400, 0, 1, 0);

	GLfloat = matAmbient[] = {1.0f,1.0f,1.0f,1.0f};
	GLfloat = matDiffuse[] = {1.0f,1.0f,1.0f,1.0f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	
	for(int i = 0; i < sphereamnt; i++) {
		s.at(i).draw();
	}
		
	glutSwapBuffers();
}

void scene::update() {
	physics P;
	P.setSphere(s);
	P.calculate(dt);
	
	glutPostRedisplay();
}

void scene::timer() {
	dt = static_cast<float>(glutGet(GLUT_ELAPSE_TIME) - time);
	time = static_cast<float>(glutGet(GL_ELAPSE_TIME) + time);
}

