#include <iostream>
#include <cmath>
#include <vector>
#include <GL/glut.h>
#include "physics.hpp"
#include "sphere.hpp"

#define PI = 3.1415926535;
#define targetDensity = 1.0;
#define presureMultiplier = 2.0;
#define dampening = 0.95;

using namespace std;

vector <double> SphereBySphere(sphere &s1, sphere &s2) {
	vector <double> S1 = s1.getPosition();
	vector <double> S2 = s2.getPosition();
	S1radius = s1.getRadius();
	S2radius = s2.getRadius();
	
	vector <double> norm;

	double dist = sqrt( (S1.at(0) - S2.at(0)) * (S1.at(0) - S2.at(0)) + (S1.at(1) - S2.at(1)) * (S1.at(1) - S2.at(1)) + (S1.at(2) - S2.at(2)) * (S1.at(2) - S2.at(2)) )
	num = dist - S1radius - S2radius;
	if((num) < 0.0) { 
	// TODO: instead of using 0.0 we use rounding for the precision error
	// TODO: find where point they meet at, we don't need to do that
	depth = {num *  (S1.at(0) - S2.at(0))/(dist),num * (S1.at(1) - S2.at(1))/(dist),num * (S1.at(2) - S2.at(2))/(dist) }
}

return depth;

}

double Dist(sphere &s1, sphere &s2) {
         vector <double> S1 = s1.getPosition();
         vector <double> S2 = s2.getPosition();
         S1radius = s1.getRadius();
         S2radius = s2.getRadius();

         vector <double> norm;

	 double dist = sqrt( (S1.at(0) - S2.at(0)) * (S1.at(0) - S2.at(0)) + (S1.at(1) - S2.at(1)) * (S1.at(1) - S2.at(1)) + (S1.at(2) - S2.at(2)) * (S1.at(2) - S2.at(2)) )   
		 num = dist - S1radius - S2radius;
 	return num;
}

double SmoothingKernal(double h, double dist) {
	if(dist < h) {
		return (10.0 / (PI * pow(h,3) * pow((1.0 - dist / h),3))
	}
	else {
	return 0.0;
	}
}

vector<double> grad_SmoothingKernal(const vector<double> &radius,double h) {
	double d = radius.length();
	if(d < h) {
		double factor = -30.0 / (PI * pow(h,4) * pow((1.0 - d / h),2));
		vector<double> res = {factor * r.at(0) / d, factor * r.at(1) / d, factor * r.at(2) / d };
		return res;
	}
	else {
	vector<double> res = {0.0,0.0,0.0};
	return res;	
}
}

double getDensity(int sphereWeWant,vector <sphere> &s) {
	// we know mass for all spheres will be same for now
	// TODO: make this algorithm better this is slow but oh well
	double density = 0.0;
	for(int i = 0; i < s.size(); i++) {
		if(i != sphereWeWant) {
			dist = Dist(s.at(sphereWeWant),s.at(i))
			
			density += s.at(i).mass() * SmoothingKernal(1, dist);
		}
	}
return density;
}



double ConvertDensityToPressure(double density) {
	double densityError = density - targetDensity;
	double pressure = densityError * pressureMultiplier;
	return pressure;
}


vector <double> SphereByPlane(sphere &s1, vector <double> &P1, vector <double> &norm, double dotx, double doty, double dotz) {
	S1 = s1.getPosition();	
	S1radius = s1.getRadius();
	vector <double> check = {dotx, doty, dotz};
	// Our goal is to stop our objects from exiting our world plane, bc if they do that is bad
	double Dist = (norm.at(0) * S1.at(0) + norm.at(1) * S1.at(1) + norm.at(2) * S1.at(2) + norm.at(3)) //note norm.at(3) may be useless;
		
	/*
		(if Dist < S1radius) {
			s1.SetPosition(Dist * norm.at(0), Dist * norm.at(1), Dist * norm.at(2));
			vector <double> velo = s1.GetVelocity();
			velo += {norm.at(0) * 2 * velo.at(0) * dampening, norm.at(1) * 2 * velo.at(1) * dampening, norm.at(2) * 2 * velo.at(2) * dampening}; // object goes backwards with less velocity
			s1.setVelocity(velo);
		}
	*/	
	if(abs(S1.at(0)) > abs(P1.at(0)) || abs(S1.at(1)) > abs(P1.at(1)) || abs(S1.at(2)) > abs(P1.at(2))) {
		s1.SetPosition(Dist * norm.at(0), Dist * norm.at(1), Dist * norm.at(2));
		 vector <double> velo = s1.GetVelocity();
		 velo += {norm.at(0) * 2 * velo.at(0) * dampening, norm.at(1) * 2 * velo.at(1) * dampening, norm.at(2) * 2 * velo.at(2) * dampening}; // object goes backwards with less velocity
		s1.setVelocity(velo);
	}
	
}

vector <double> ForceOfWater(int sphereWeWant, vector <sphere> &s) {
	vector <double> force = {0.0,0.0,0.0};
	for(int j = 0; j < s.size(); j++) {
	if(j != sphereWeWant) {    
	for(int i = 0; i < 3; i++) {
		double dist = Dist(s.at(sphereWeWant),s.at(j))
		vector<double> grad = grad_SmoothingKernal(dist, 1); 
		force.at(i) = (-s.at(spherWeWant).GetMass() + s.at(j).GetMass() * (s.at(sphereWeWant).GetPressure() + s.at(j).GetPressure()) / (2*s.at(j).getDensity * grad.at(0))

}

}

}
return force;
}

// TODO: I might need to use a hash table algorithm to get this faster but im too lazy

void physics::Collision() {
	
}



void physics::Step(double dt) {
	
	double smoothingRad = 1.0;
	vector <double> grav = {0.0,0.0,9.81};
	
	// The first thing we do is apply gravity to all the particles
	// TODO: make this algorithm less than O(n^2)
	// Get density and density stuff
	
	for(int j = 0; j < s.size(); j++) {
	
	vector <double> total_force = grav;
	
	total_force += ForceOfWater(j, s);
	
	s.at(j).setForce(total_force);
}
	//Now we have forces now we can calculate the accelerations and velocities
	
for(int i = 0; i < s.size(); i++) {
	
	vector <double> velo = {0.0,0.0,0.0};
	
	for(int j = 0; j < 3; j++) {
		velo.at(j) = s.at(i).GetVelocity().at(j) + dt * s.at(i).getForce().at(j);
		}
	s.at(i).SetVelocity(velo);
	}
	
	// Finally we change position
	current_time = current_time + dt;
	
	for(int i = 0; i < s.size(); i++) {
		vector<double> pos = s.at(i).getPosition() + dt * s.at(i).GetVelocity;
		s.at(i).setPosition(pos);
	}
}
