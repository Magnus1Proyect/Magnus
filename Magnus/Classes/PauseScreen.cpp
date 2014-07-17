#include "PauseScreen.h"

// The version of PauseScreen.cpp was removed until it works.

USING_NS_CC;

Scene* PauseScreen::createScene() {
	// 'scene' is an autorelease object, its the space where the action happens.
	auto scene = Scene::create();

	// 'layer' is an autorelease object, each layer represents stages of the action.
	auto layer = PauseScreen::create();

	// add layer as a child to scene. Lets see it like a tree, action.
	scene->addChild(layer);

	// return the scene. We put the scene back and now its alive
	return scene;
}

// We  initialize our instance
bool PauseScreen::init() {
	// 1. super init first
	if (!Layer::init()) { // if there is a mistake then we terminate the program, it couldnt launch
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// add a label shows "Creditos" create and initialize labels

	auto labelTitulo = LabelTTF::create("Pausa", "Tahoma", 40);

	// position the label on the upper center of the screen
	labelTitulo->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .88f));

	// add the label as a child to this layer
	this->addChild(labelTitulo, 1);

	// Creates the background of the game menu.
	auto sprite = Sprite::create("GameMenu/0000.jpg"); // sprites are important, those are the images
	// position the sprite on the center of the screen
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	createMenu(); // We bring to live this scene.

	return true; // we managed to bring frankestein alive, I mean, the game.
}

void PauseScreen::createMenu() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
}