#ifndef Power_H
#define Power_H

#include "cocos2d.h"

class Power{

public:

	Power::Power();
	Power::Power(const char* powerName, bool solid, bool water, bool ice, bool fire);

	cocos2d::Sprite *powerSprite;

	const char* Power::getName();
	bool Power::getSolid();
	bool Power::getWater();
	bool Power::getIce();
	bool Power::getFire();

	void Power::setName(const char* n);
	void Power::setPower(const char* powerName, bool solid, bool water, bool ice, bool fire);
	void Power::setPower(Power p);
	void Power::setSolid(bool b);
	void Power::setWater(bool b);
	void Power::setIce(bool b);
	void Power::setFire(bool b);

	cocos2d::Point Power::getPosition();
	cocos2d::Sprite* Power::getSprite();

	void Power::loadSprite(const char* dir);

	void Power::setPosition(float x, float y);
	void Power::setPosition(cocos2d::Point pos);

};

#endif /Power_H