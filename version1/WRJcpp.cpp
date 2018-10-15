
#include "pch.h"
#include "WRJ.h"
#include <fstream>
#include <iostream>

using namespace std;

float step = 0.1;

WRJ::WRJ() {
	quality = 1;
	power = 0;
	return;
}

float WRJ::getPower() {
	return power;
}

float WRJ::getQuality() {
	return quality;
}

float WRJ::get_leanX() {
	return leanX;
}

float WRJ::get_leanZ() {
	return leanZ;
}

void WRJ::upPower() {
	power += step;
}

void WRJ::downPower() {
	power -= step;
}

void WRJ::go_left() {
	leanX -= step;
}

void WRJ::go_right() {
	leanX += step;
}

void WRJ::go_ahead() {
	leanZ -= step;
}

void WRJ::go_back() {
	leanZ += step;
}

void WRJ::hover() {
	float gravity = quality * 9.8;
	if (power < gravity)upPower();
	if (power > gravity)downPower();

	if (leanX > 0)leanX--;
	if (leanX < 0)leanX++;
	if (leanZ > 0)leanZ--;
	if (leanZ < 0)leanZ++;
	return;
}
 



/*
float hover() {
	
}
float rise() {

}
float drop() {

}
float go_left() {
	
}
float go_right() {

}
float go_ahead() {

}
float go_back() {

}
*/