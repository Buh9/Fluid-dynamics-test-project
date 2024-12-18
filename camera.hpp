#ifndef CAMERA_H_
#define CAMERA_H_

#include <iostream>
#include <vector>
#include <GL/glut.h>

class camera {
	private:
	int mousex;
	int mousey;
	float xangle;
	float yangle;
	float zangle;
	float theta;
	float psi;
	public:
	camera() {
	mousex = 0;
	mousey = 0;
	xangle = 0.0;
	yangle = 0.0;
	zangle = 0.0;
	psi = 0.0;
	theta = 0.0;
	}
	camera(double p, double t) {
	mousex = 0;
	mousey = 0;
	xangle = 0.0;
	yangle = 0.0;
	zangle = 0.0;
	psi = p;
	theta = t;
	}
	void update(int, int);
	float getXangle(){ 
		return xangle;
       	}
	float getYangle(){
		return yangle;		
	}
	float getZangle(){ 
		return zangle; 
	}
};

#endif // CAMERA_H_
