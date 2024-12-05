#ifndef PHYISCS_H_
#define PHYSICS_H_

#include <iostream>
#include <vector>
#include "sphere.hpp"
#include <GL/glut.h>


using namespace std;
class physics{
	private:
	vector <sphere> *s = nullptr;
	double current_time;
	public:
	
	physics() {
	s = nullptr;
	}
	void SetSphere(vector <sphere> &sph) {
		s = &sph;
	}
	/*	
	~physics() {
	delete s;
	}
	*/
	void Collision(double);
	void Step(double dt);
};

#endif //PHYISCS_H_
