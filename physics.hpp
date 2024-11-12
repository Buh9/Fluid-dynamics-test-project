#ifndef PHYISCS_H_
#define PHYSICS_H_

#include <iostream>
#include <vector>
#include "sphere.hpp"
#include <GL/glut.h>

using namespace std;
class Physics{
	private:
	vector <sphere> *s = nullptr;
	vector <double> Plane1;
	vector <double> Plane2;
	vector <double> Plane3;
	vector <double> Plane4;
	vector <double> Plane5;
	double current_time;
	public:
	void Collision();
	void Step(double dt);
};


#endif PHYISCS_H_
