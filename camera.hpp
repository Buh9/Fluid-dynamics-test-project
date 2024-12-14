#include <iostream>
#include <vector>
#include <GL/glut.h>

class cam {
	private:
	int mousex;
	int mousey;
	float xangle;
	float yangle;
	float zangle;
	float theta;
	float psi;
	public:
	cam() {
	mousex = 0;
	mousey = 0;
	xangle = 0.0f;
	yangle = 0.0f;
	zangle = 0.0f;
	yaw = 0.0f;
	theta = 0.0f;
	}
	void update(int, int);
	float getXangle(){ 
		return xangle;
       	}
	float getYangle(){
		
	}
	float getZangle(){ 
		return zangle; 
	}
};
