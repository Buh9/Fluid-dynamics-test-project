#include <iostream>
#include <cmath>
#include <vector>
#include <GL/glut.h>
#include "physics.hpp"
#include "sphere.hpp"

#define PI 3.1415926535
#define targetDensity 1.0
#define pressureMultiplier 2.0
#define dampening 0.95

using namespace std;

vector <double> SphereBySphere(sphere &s1, sphere &s2) {
	vector <double> S1 = s1.getPosition();
	vector <double> S2 = s2.getPosition();
	double S1radius = s1.getRadius();
	double S2radius = s2.getRadius();
	
	vector <double> depth;

	double dist = sqrt( (S1.at(0) - S2.at(0)) * (S1.at(0) - S2.at(0)) + (S1.at(1) - S2.at(1)) * (S1.at(1) - S2.at(1)) + (S1.at(2) - S2.at(2)) * (S1.at(2) - S2.at(2)) );
	double num = dist - S1radius - S2radius;
	if((num) < 0.0) { 
	// TODO: instead of using 0.0 we use rounding for the precision error
	// TODO: find where point they meet at, we don't need to do that
	depth = {num *  (S1.at(0) - S2.at(0))/(dist),num * (S1.at(1) - S2.at(1))/(dist),num * (S1.at(2) - S2.at(2))/(dist) };
}

return depth;

}

double Dist(sphere &s1, sphere &s2) {
         vector <double> S1 = s1.getPosition();
         vector <double> S2 = s2.getPosition();
         double S1radius = s1.getRadius();
         double S2radius = s2.getRadius();

         vector <double> norm;

	 double dist = sqrt( (S1.at(0) - S2.at(0)) * (S1.at(0) - S2.at(0)) + (S1.at(1) - S2.at(1)) * (S1.at(1) - S2.at(1)) + (S1.at(2) - S2.at(2)) * (S1.at(2) - S2.at(2)) );   
		 double num = dist - S1radius - S2radius;
 	return num;
}

double SmoothingKernal(double h, double dist) {
	if(dist < h) {
		return (10.0 / (PI * pow(h,3) * pow((1.0 - dist / h),3)));
	}
	else {
	return 0.0;
	}
}

vector<double> grad_SmoothingKernal(const vector<double> &radius,double h) {
	double d = radius.at(1);
	if(d < h) {
		double factor = (-30.0 / (PI * pow(h,4) * pow((1.0 - d / h),2)));
		vector<double> res = { factor * radius.at(0) / d, factor * radius.at(1) / d, factor * radius.at(2) / d };
		return res;
	}
	else {
	vector<double> res = {0.0,0.0,0.0};
	return res;	
}
}

double CalcDensity(int sphereWeWant,vector <sphere> &s) {
	// we know mass for all spheres will be same for now
	// TODO: make this algorithm better this is slow but oh well
	double density = 0.0;
	
	for(int i = 0; i < s.size(); i++) {
		if(i != sphereWeWant) {
			double dist = Dist(s.at(sphereWeWant),s.at(i));
			
			density += s.at(i).getMass() * SmoothingKernal(1, dist);
		}
	}
return density;
}


void ConvertDensityToPressure(int sphereWeWant, vector <sphere> &s) {
	double densityError = s.at(sphereWeWant).getDensity() - targetDensity;
	double pressure = densityError * pressureMultiplier;
	s.at(sphereWeWant).setPressure(pressure);
}


void SphereByBounderies(sphere &s1, double xmin, double xmax, double ymin, double ymax, double zmin, double zmax) {
	vector <double>S1 = s1.getPosition();	
	double S1radius = s1.getRadius();
	if(S1.at(0) - S1radius < xmin) {
		s1.setPosition(xmin + S1radius, S1.at(1), S1.at(2));
		vector <double> velo = s1.getVelocity();
		velo = {-1 * velo.at(0) * dampening, velo.at(1), velo.at(2) };
		s1.setVelocity(velo);
	}
	
	if(S1.at(0) - S1radius > xmax) {
		s1.setPosition(xmax - S1radius, S1.at(1), S1.at(2));
                vector <double> velo = s1.getVelocity();
                velo = {-1 * velo.at(0) * dampening, velo.at(1), velo.at(2) };
        	s1.setVelocity(velo);
	}
	
	if(S1.at(0) - S1radius < ymin) {
		s1.setPosition(S1.at(0), ymin + S1radius, S1.at(2));
                vector <double> velo = s1.getVelocity();
                velo = {velo.at(0), -1 * velo.at(1) * dampening, velo.at(2) };
		s1.setVelocity(velo);
	}
		
	if(S1.at(0) - S1radius > ymax) {
		s1.setPosition(S1.at(0), ymax - S1radius, S1.at(2));
                vector <double> velo = s1.getVelocity();
                velo = {velo.at(0), -1 * velo.at(1) * dampening, velo.at(2) };
		s1.setVelocity(velo);
	}
	
	
	if(S1.at(0) - S1radius < zmin) {
		s1.setPosition(S1.at(0), S1.at(1), zmin + S1radius);
                vector <double> velo = s1.getVelocity();
                velo = {velo.at(0), velo.at(1), -1 * velo.at(2) *dampening };
		s1.setVelocity(velo);
	}

	
	if(S1.at(0) - S1radius > zmax) {
		s1.setPosition(S1.at(0), S1.at(1), zmax - S1radius);
                vector <double> velo = s1.getVelocity();
                velo = {velo.at(0), velo.at(1), -1 * velo.at(2) *dampening };
		s1.setVelocity(velo);
	}

}

vector <double> ForceOfWater(int sphereWeWant, vector <sphere> &s) {
	
	vector <double>force = { 0.0,0.0,0.0 };
	
	for(int j = 0; j < s.size(); j++) {
	if(j != sphereWeWant) {    
	for(int i = 0; i < 3; i++) {
		double dist = Dist(s.at(sphereWeWant),s.at(j));
		
		//vector <double>grad = grad_SmoothingKernal(dist, 1); 
		
		force.at(i) = (-s.at(sphereWeWant).getMass() + s.at(j).getMass() * (s.at(sphereWeWant).getPressure() + s.at(j).getPressure()) / (2*s.at(j).getDensity()));

		}

	}

}
return force;
}

// TODO: I might need to use a hash table algorithm to get this faster but im too lazy

void physics::Collision() {
	for(int i = 0; i < s->size(); i++) {
	SphereByBounderies(s->at(i),-500,500,-500,500,-1000,1000);
	}
	for(int i = 0; i < s->size(); i++) {
		for(int j = 0; j < s->size(); j++) {
		SphereBySphere(s->at(i),s->at(j));
		}
	}
}



void physics::Step(double dt) {
	
	double smoothingRad = 1.0;
	// vector <double> grav = {0.0,0.0,9.81};
	
	// The first thing we do is apply gravity to all the particles
	// TODO: make this algorithm less than O(n^2)
	// Get density and density stuff
	for(int i = 0; i < s->size(); i++) {
		CalcDensity(i, *s);
	}

	// Right Now I am going to test if the objects even move;

	/* This is actual SPH code 


	for(int j = 0; j < s->size(); j++) {
	
	vector <double> force2 = ForceOfWater(j, *s);

	vector <double> total_force = {force2.at(0) + grav.at(0), force2.at(1) + grav.at(1), force2.at(2) + grav.at(2)};
	
	s->at(j).setForce(grav);
}
	//Now we have forces now we can calculate the accelerations and velocities
	

	*/


for(int i = 0; i < s->size(); i++) {
	
	vector <double> velo = {0.0,0.0,0.0};
	
	for(int j = 0; j < 3; j++) {
		velo.at(j) = s->at(i).getVelocity().at(j) + dt * s->at(i).getForce().at(j);
		}
	s->at(i).setVelocity(velo);
	}
	
	// Finally we change position
	current_time = current_time + dt;
	
	for(int i = 0; i < s->size(); i++) {
		
		vector <double> pos = {0.0,0.0,0.0};
		vector <double> pos2 = s->at(i).getPosition();
		/*
		 * still more testing 
		vector <double> velo = s->at(i).getVelocity();
		*/
		vector <double> velo = {0.000001, 0.000001, 0.0};
		for(int j = 0; j < 3; j++) {
			pos.at(j) = pos2.at(j) + dt * velo.at(j);
		}

		s->at(i).setPosition(pos);
	
	}
}
