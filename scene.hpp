#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "camera.hpp"
#include "sphere.hpp"
#include "physics.hpp"

class scene {
	private:
	vector<sphere> s;
	float dt;
	float time;
	public:
	void initGL();
	void display(int);
	void update(double);
	void timer();
};






#endif SCENE_H_
