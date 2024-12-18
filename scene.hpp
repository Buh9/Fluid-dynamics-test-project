#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "camera.hpp"
#include "sphere.hpp"

class scene {
	private:
	vector<sphere> s;
	float dt;
	float time;
	camera camera2;
	public:
	void sphereinit(int);
	void initGL(int);
	void display(int);
	void update(int);
	void timer();
	void updatecam(int, int);
};






#endif // SCENE_H_
