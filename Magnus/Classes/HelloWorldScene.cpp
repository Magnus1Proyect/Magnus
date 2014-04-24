#include "HelloWorldScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = LabelTTF::create("v0.1", "Arial", 16);

	// position the label on the center of the screen
	label->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .7f));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// Crear el fondo del menu del juego
	auto sprite = Sprite::create("GameMenu/0000.jpg");

	// position the sprite on the center of the screen
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	createGameTitle();
	createGameMenu();

	// Reproducir la musica del menu principal
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/trivia.mp3", true);

	return true;
}

void HelloWorld::createGameTitle()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Colocar la imagen estatica con el titulo o nombre del juego en la pantalla
	auto gameTitle = Sprite::create("GameMenu/002-Title0.png");
	gameTitle->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - gameTitle->getContentSize().height - 20.0f));
	this->addChild(gameTitle, 0);

	// Hacer una animacion con el titulo del juego cambiando su imagen (textura) en el tiempo
	auto animation = Animation::create();
	for (int i = 0; i < 5; ++i)
		animation->addSpriteFrameWithFile(String::createWithFormat("GameMenu/002-Title%i.png", i)->getCString());

	// Y luego regresarla a su estado inicial
	for (int i = 4; i >= 0; --i)
		animation->addSpriteFrameWithFile(String::createWithFormat("GameMenu/002-Title%i.png", i)->getCString());

	// Indicarle que muestre cada una de las imagenes que la componen por 0.1333 segundos
	animation->setDelayPerUnit(0.1333f);

	// Lo anterior construye una unica animacion, repetirla siempre y cuando la pantalla de
	// menu del juego este visible
	auto repeatAnimation = RepeatForever::create(Animate::create(animation));
	gameTitle->runAction(repeatAnimation);
}

void HelloWorld::createGameMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Boton para iniciar el juego, situado a un 50% de la altura de la pantalla
	auto buttonNewGame = MenuItemImage::create("GameMenu/003-NewGame.png", "GameMenu/003-NewGame01.png", CC_CALLBACK_1(HelloWorld::newGame, this));
	buttonNewGame->setPosition(Point(visibleSize.width / 2, origin.y + visibleSize.height * 0.57f));
	auto buttonNewGameMenu = Menu::create(buttonNewGame, NULL);
	buttonNewGameMenu->setPosition(Point::ZERO);
	this->addChild(buttonNewGameMenu, 2);

	// Boton de load, situado debajo del boton iniciar
	auto buttonLoadGame = MenuItemImage::create("GameMenu/004-LoadGame.png", "GameMenu/004-LoadGame01.png", CC_CALLBACK_1(HelloWorld::loadGame, this));
	buttonLoadGame->setPosition(Point(buttonNewGame->getPositionX(), buttonNewGame->getPositionY() - buttonNewGame->getContentSize().height - 10));
	auto buttonLoadGameMenu = Menu::create(buttonLoadGame, NULL);
	buttonLoadGameMenu->setPosition(Point::ZERO);
	this->addChild(buttonLoadGameMenu, 2);


	// Boton de opciones, situado debajo del boton anterior
	auto buttonOptions = MenuItemImage::create("GameMenu/005-Options.png", "GameMenu/005-Options01.png", CC_CALLBACK_1(HelloWorld::showOptions, this));
	buttonOptions->setPosition(Point(buttonLoadGame->getPositionX(), buttonLoadGame->getPositionY() - buttonLoadGame->getContentSize().height - 10));
	auto buttonOptionsMenu = Menu::create(buttonOptions, NULL);
	buttonOptionsMenu->setPosition(Point::ZERO);
	this->addChild(buttonOptionsMenu, 2);


	// Boton de trofeos, situado debajo del boton anterior
	auto buttonAwards = MenuItemImage::create("GameMenu/004-LoadGame.png", "GameMenu/004-LoadGame.png", CC_CALLBACK_1(HelloWorld::showAwards, this));
	buttonAwards->setPosition(Point(buttonOptions->getPositionX(), buttonOptions->getPositionY() - buttonOptions->getContentSize().height - 10));
	auto buttonAwardsMenu = Menu::create(buttonAwards, NULL);
	buttonAwardsMenu->setPosition(Point::ZERO);
	this->addChild(buttonAwardsMenu, 2);


	// Boton de exit, situado debajo del boton anterior (de ultimo)
	auto buttonExit = MenuItemImage::create("GameMenu/006-Exit.png", "GameMenu/006-Exit01.png", CC_CALLBACK_1(HelloWorld::exitGame, this));
	buttonExit->setPosition(Point(buttonAwards->getPositionX(), buttonAwards->getPositionY() - buttonAwards->getContentSize().height - 10));
	auto buttonExitMenu = Menu::create(buttonExit, NULL);
	buttonExitMenu->setPosition(Point::ZERO);
	this->addChild(buttonExitMenu, 1);
}

#include "LevelSelectScene.h"
void HelloWorld::newGame(Ref* pSender)
{
		
	// AQUI DEBE IR ANIMACIÓN DE PUERTAS

	auto newScene = LevelSelectScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}

void HelloWorld::loadGame(Ref *pSender)
{
}


void HelloWorld::showAwards(Ref *pSender)
{
}

void HelloWorld::showOptions(cocos2d::Ref *pSender)
{
}

void HelloWorld::exitGame(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

