#ifndef Player_H
#define Player_H

#include "cocos2d.h"
#include "Power.h"

class Player{

public:
	Player::Player();
	// Jugador
	/**
	@brief We bring and set the player Sprite.
	@param The parameters we need in this method are used to place the sprite in a certain place in the screen. The first param: char, refers to north, south, east or west
	*/
	void Player::loadSprite(const char* dir, float xStart, float yStart, float xSize, float ySize);

	void Player::setSprite(cocos2d::Sprite* s);

	/**
	@brief Sets a certain power to the player.
	@param Power p, the power in cuestion
	*/
	void Player::setPower(Power p);
	/**
	@brief Sets a certain power to the player.
	@param const char* powerName the power Name
	@param bool each of this param work by being true for the one they affect and false on the others.
	Example: fireproof power will have (fireproof, false, false, false, true);
	*/
	void Player::setPower(const char* powerName, bool solid, bool water, bool ice, bool fire);

	void Player::setPosition(float x, float y);

	void Player::setPosition(cocos2d::Point pos);

	cocos2d::Point Player::getPosition();

	cocos2d::Sprite* Player::getSprite();

	/**
	@brief Returns the power the player currently holds
	@return Power Returns the active power. If it has ice for example it will return @ice
	*/
	Power Player::getPower();
};

#endif// Player_H