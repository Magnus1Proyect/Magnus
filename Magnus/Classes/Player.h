#ifndef Player_H
#define Player_H

#include "cocos2d.h"
#include "Power.h"

class Player{

public:
	// Jugador
	/**
	@brief We bring and set the player Sprite.
	*/
	void Player::loadSprite(const char* dir, float xStart, float yStart, float xSize, float ySize);

	void Player::setSprite(cocos2d::Sprite* s);

	void Player::setPower(Power p);

	void Player::setPosition(float x, float y);

	void Player::setPosition(cocos2d::Point pos);

	cocos2d::Point Player::getPosition();

	cocos2d::Sprite* Player::getSprite();

	Power Player::getPower();
};

#endif// Player_H