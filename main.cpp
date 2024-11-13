#include <iostream>
#include <GL/glut.h>
#include "scene.hpp"

using namespace std;

unsigned int WIDTH = 800;
unsigned int HEIGHT = 600;

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(WIDTH,HEIGHT);

	glutInitWindowPosition(20,30);

	glutCreateWindow("Volume Test");

	/*TODO: Get a glut stuff working properly*/
	
	glutDisplayFunc(scene.initGL()); 	// Scene displaying function
	glutIdleFunc(scene.update()); 	// This updates the scene for it repeats
	// glutReshapeFunc(); 	 For window resizing
	// glutKeyboardFunc(); 	 For keyboard input
	// glutSpecialFunc(); 	// For special keys?
	
	// Enters the main loop and processing events
	glutMainLoop();

	return 0;
}

