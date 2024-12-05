#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "camera.hpp"
#include "sphere.hpp"
#include "physics.hpp"
#include "scene.hpp"
#include <chrono>
// TODO: weird fix around with a global variable since glut timer sucks

double took;

void scene::sphereinit(int sphereamnt) {
	time = 0.0;
	dt = 0.0001;
	sphere s1;

		for(int j = 0; j < sphereamnt; j++) {
			s.push_back(s1);
		}
		
		for(int k = 0; k < sphereamnt; k++) {
			s.at(k).setPosition( -0.3 + 0.05 * (k / 2), -0.3 + 0.05 * (k % 2), 0);
		}
}


void scene::initGL(int sphereamnt) {
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
	
	//TODO: get a better way of creating the spheres
	sphere s1;
	
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
	
	
	for(int i = 0; i < sphereamnt; i++) {
		s.at(i).draw();
	}	
	
	
	glutSwapBuffers();
}

void scene::update(int sphereamnt) {
	auto start = chrono::high_resolution_clock::now();
	physics P;
	P.SetSphere(s);
	P.Step(dt);
	P.Collision(dt);	

		
	for(int i = 0; i < sphereamnt; i++) {
		s.at(i).draw();
	}	

	glutPostRedisplay();
	auto end = chrono::high_resolution_clock::now();
	took = chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}
void scene::timer() {
	dt = took * 0.0000001;
	cout << "dt: " << dt << endl;
	time = dt + time;	
}

