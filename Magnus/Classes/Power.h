#ifndef Power_H
#define Power_H

#include "cocos2d.h"

class Power{

public:

	Power();
	Power(const char* powerName, bool solid, bool water, bool ice, bool fire);

	cocos2d::Sprite *powerSprite;

	const char* getName();
	bool getSolid();
	bool getWater();
	bool getIce();
	bool getFire();

	void setName(const char* n);
	void setPower(const char* powerName, bool solid, bool water, bool ice, bool fire);
	void setPower(Power p);
	void setSolid(bool b);
	void setWater(bool b);
	void setIce(bool b);
	void setFire(bool b);

	cocos2d::Point getPosition();
	cocos2d::Sprite* getSprite();

	void loadSprite(const char* dir);

	void setPosition(float x, float y);
	void setPosition(cocos2d::Point pos);

};

#endif /Power_H
