#include <iostream>
#include <GL/glut.h>
#include "scene.hpp"



using namespace std;

unsigned int WIDTH = 800;
unsigned int HEIGHT = 600;
scene sc;

void displayCall() {
	sc.display(10);
}

void updateCall() {
	sc.update(10);
	sc.timer();
}


int main(int argc, char** argv) {
	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(WIDTH,HEIGHT);

	glutInitWindowPosition(100,100);

	glutCreateWindow("Volume Test");

	/*TODO: Get a glut stuff working properly*/
	sc.sphereinit(10);	

	sc.initGL(10);
	sc.timer();
	glutDisplayFunc(displayCall); 	// Scene displaying function
	glutIdleFunc(updateCall); 	// This updates the scene for it repeats
	// glutReshapeFunc(); 	 For window resizing
	// glutKeyboardFunc(); 	 For keyboard input
	// glutSpecialFunc(); 	// For special keys?
	
	// Enters the main loop and processing events
	glutMainLoop();

	return 0;
}

