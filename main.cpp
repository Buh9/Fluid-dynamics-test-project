#include <iostream>
#include <GL/glut.h>

using namespace std;

unsigned int WIDTH = 800;
unsigned int HEIGHT = 600;

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(WIDTH,HEIGHT);

	glutInitWindowPosition(0,0);

	glutCreateWindow("Volume Test");
	
	/*TODO: Get a glut stuff working properly*/
	
	glutDisplayFunc(); 	// Scene displaying function
	glutIdleFunc(); 	// This updates the scene for it repeats
	glutReshapeFunc(); 	// For window resizing
	glutKeyboardFunc(); 	// For keyboard input
	glutSpecialFunc(); 	// For special keys?
	
	// Enters the main loop and processing events
	glutMainLoop();

	return 0;
}

