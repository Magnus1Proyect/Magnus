#include "Power.h"

const char* name;
bool solid;
bool water;
bool ice;
bool fire;

Power::Power(){};

Power::Power(const char* n, bool so, bool wa, bool ic, bool fi){
	name = n;
	solid = so;
	water = wa;
	ice = ic;
	fire = fi;
};


const char* Power::getName(){
	return name;
};
bool Power::getSolid(){
	return solid;
};
bool Power::getWater(){
	return water;
};
bool Power::getIce(){
	return ice;
};
bool Power::getFire(){
	return fire;
};

void Power::setPower(const char* n, bool so, bool wa, bool ic, bool fi){
	name = n;
	solid = so;
	water = wa;
	ice = ic;
	fire = fi;
};

void Power::setPower(Power p){
	name = p.getName();
	solid = p.getSolid();
	water = p.getWater();
	ice = p.getIce();
	fire = p.getFire();
};

void Power::setName(const char* n){
	name = n;
}

void Power::setSolid(bool b){
	solid = b;
};
void Power::setWater(bool b){
	water = b;
};
void Power::setIce(bool b){
	ice = b;
};
void Power::setFire(bool b){
	fire = b;
};