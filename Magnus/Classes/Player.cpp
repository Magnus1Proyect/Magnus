#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

//TULSI POWER
Power playerPower;
cocos2d::Sprite *playerSprite;

Player::Player(){
	playerPower.setPower("default", false, false, false, false);
	playerSprite=nullptr;
}

void Player::loadSprite(const char* dir, float xStart, float yStart, float xSize, float ySize){
	cocos2d::Sprite* temp = cocos2d::Sprite::create(dir, cocos2d::Rect(xStart, yStart, xSize, ySize));
	playerSprite = temp;
}

void Player::setSprite(cocos2d::Sprite* s){
	playerSprite = s;
}

void Player::setPower(Power p){
	playerPower = p;
}

void Player::setPower(const char* powerName, bool solid, bool water, bool ice, bool fire){
	playerPower.setPower(powerName, solid, water, ice, fire);
}

void Player::setPosition(float x, float y){
	playerSprite->setPosition(x, y);
}

void Player::setPosition(cocos2d::Point pos){
	playerSprite->setPosition(pos);
}

cocos2d::Point Player::getPosition(){
	return playerSprite->getPosition();
}

cocos2d::Sprite* Player::getSprite(){
	return playerSprite;
}

Power Player::getPower(){
	return playerPower;
}