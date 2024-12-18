#include <iostream>
#include <vector>
#include <GL/glut.h>
#include <cmath>
#include "camera.hpp"
#define PI 3.1415926535

void camera::update(int x, int y) {
	psi -= static_cast<float>(x - mousex) * 0.25;
	theta += static_cast<float>(y - mousey) * 0.25;
	if(theta > 89.0f) {
	theta = 89.0f;
	}
	if(theta < -89.0f) {
	theta = -89.0f;
	}
	xangle = cos((psi * PI) / 180 ) * cos((theta * PI) / 180 );
	yangle = sin((theta * PI) / 180);
	zangle = sin((psi * PI) / 180 ) * cos((theta * PI) / 180);

	mousex = x;
	mousey = y;
}

