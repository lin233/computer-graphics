#pragma once

#pragma once
 
#include <vector>
#include <string>
#include <iostream>
#include <map>;
using namespace std;

 
class WRJ {
public:
	WRJ();
	float getPower();
	float getQuality();
	float get_leanX();
	float get_leanZ();

	void upPower();
	void downPower();
	void go_left();
	void go_right();
	void go_ahead();
	void go_back();
	void hover();

private:

	float quality;
	float power;
	float leanX;
	float leanZ;

   
};


/*
class Movement {
public:
	Movement(float,float,float,float);
	float get_aX(float ForceX);
	float get_aY(float ForceY);
	float get_aZ(float ForceZ);

private:
	WRJ wrj;

}

class Manipulation {
public:
	Manipulation();
	float hover();
	float rise();
	float drop();
	float go_left();
	float go_right();
	float go_ahead();
	float go_back();

private:
	WRJ wrj;
	float leanX;
	float leanZ;
};
*/