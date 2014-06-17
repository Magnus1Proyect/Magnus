#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

//TULSI POWER
Power playerPower;
cocos2d::Sprite *playerSprite;

void Player::loadSprite(const char* dir, float xStart, float yStart, float xSize, float ySize){
	playerSprite = cocos2d::Sprite::create(dir, cocos2d::Rect(xStart, yStart, xSize, ySize));	
}

void Player::setSprite(cocos2d::Sprite* s){
	playerSprite = s;
}

void Player::setPower(Power p){
	
	playerPower = p;
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