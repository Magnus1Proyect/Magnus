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
	playerSprite = cocos2d::Sprite::create(dir, cocos2d::Rect(xStart, yStart, xSize, ySize));	
}

void Player::setSprite(cocos2d::Sprite* s){
	playerSprite = s;
}

void Player::setPower(Power p){
	playerPower.setName(p.getName());
	playerPower.setSolid(p.getSolid());
	playerPower.setWater(p.getWater());
	playerPower.setIce(p.getIce());
	playerPower.setFire(p.getFire());
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

PowerList Player::getList(){
	return powers;
}