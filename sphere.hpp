#ifndef SPHERE_H_
#define SPHERE_H_

#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;
class sphere{
	private:
	double X,Y,Z;
	double radius;
	vector <double> velocity;
	vector <double> force;
	double mass;
	double fluidDensity;
	public:
	sphere() {
	X = 0.0;
	Y = 0.0;
	Z = 0.0;
	force = {0.0,0.0,0.0}
	velocity = {0.0, 0.0, 0.0};
	radius = 1.0;
	mass = 1.0;
	fluidDensity = 0.0;
	}
	
	sphere(double xcoord, double ycoord, double zcoord, double r) {
		X = xcoord;
		Y = ycoord;
		Z = zcoord;
		radius = r;
		velocity = {0.0, 0.0, 0.0};
		force = {0.0,0.0,0.0};
		mass = 1.0;
	}
	sphere(double xcoord, double ycoord, double zcoord, double r, double m) {
		X = xcoord;
		Y = ycoord;
		Z = zcoord;
		radius = r;
		velocity = {0.0, 0.0, 0.0};
		force = {0.0,0.0,0.0};
		mass = m;
	}


	void draw();
	void setVelocity(double xvel, double yvel, double zvel) {
	velocity.at(0) = xvel;
	velocity.at(1) = yvel;
	velocity.at(2) = zvel;
	}
	void setVelocity(vector <double> vel) {
		for(int i = 0; i < 3; i++) {
			velocity.at(i) = vel.at(i);
		}
	}
	void setMass(double m) {
		mass = m;
	}
	void setForce(double xfor, double yfor, double zfor){
		force.at(0) = xfor;
		force.at(1) = yfor;
		force.at(2) = zfor;
	}
	void setForce(vector <double> f) {
		for(int i = 0; i < 3; i++) {
			force.at(i) = f.at(i);
		}
	}
	vector <double> getPosition() {
		vector <double> Pos = {X, Y, Z};
		return Pos;
	}
	vector <double> getVelocity() {
		return velocity;
	}
	vector <double> getForce() {
		return force;
	}
	double getMass() {
		return mass;
	}
	void setPosition(double xcoord, double ycoord, double zcoord) {
		X = xcoord;
		Y = ycoord;
		Z = zcoord;
	}
	void setDensity(double d) {
		fluidDensity = d;
	}
	double getDensity() {
		return fluidDensity;
	}
};


#endif SPHERE_H_
