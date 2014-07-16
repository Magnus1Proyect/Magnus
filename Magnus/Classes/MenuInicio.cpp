#include "MenuInicio.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* MenuInicio::createScene() {
	// 'scene' is an autorelease object, its the space where the action happens.
	auto scene = Scene::create();

	// 'layer' is an autorelease object, each layer represents stages of the action.
	auto layer = MenuInicio::create();

	// add layer as a child to scene. Lets see it like a tree, action.
	scene->addChild(layer);

	// return the scene. We put the scene back and now its alive
	return scene;
}

// We  initialize our instance
bool MenuInicio::init() {
	// 1. super init first
	if (!Layer::init()) 	{  // if there is a mistake then we terminate the program, it couldnt launch
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	/////////////////////////////

	// create and initialize a label showing "v0.1"

	auto label = LabelTTF::create("v0.1", "Arial", 16);

	// position the label on the center of the screen
	label->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .7f));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// We create the background of the game menu
	auto sprite = Sprite::create("GameMenu/0000.jpg");

	// position the sprite on the center of the screen
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	// We put the game title above the background and the game menu right below.
	createGameTitle();
	createGameMenu();

	// Reproducir la musica del menu principal
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic(); // this steps are to change tracks.
	//sound->playBackgroundMusic("Music/Magnus.mp3", true); // // We start our rock and roll, the Magnus piece of music starts reproducing for this scene.

	return true;
}

void MenuInicio::createGameTitle() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin(); // We look for a point to start.

	// We set out image with the game menu and the game tittle
	auto gameTitle = Sprite::create("GameMenu/002-Title0.png");
	gameTitle->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - gameTitle->getContentSize().height - 20.0f));
	this->addChild(gameTitle, 0);

	//// We animate the game tittle by making it shake and show it in time
	//auto animation = Animation::create();
	//for (int i = 0; i < 3; ++i)
	//	animation->addSpriteFrameWithFile(String::createWithFormat("GameMenu/002-Title%i.png", i)->getCString());

	//// What we are doing is changing picture orientation, we have 3 pictures and we change them accordenly so they appear to be animated.
	//for (int i = 2; i >= 0; --i)
	//	animation->addSpriteFrameWithFile(String::createWithFormat("GameMenu/002-Title%i.png", i)->getCString());

	//// Indicarle que muestre cada una de las imagenes que la componen por 0.1333 segundos
	//animation->setDelayPerUnit(0.1333f);

	//// Lo anterior construye una unica animacion, repetirla siempre y cuando la pantalla de
	//// menu del juego este visible
	//auto repeatAnimation = RepeatForever::create(Animate::create(animation));
	//gameTitle->runAction(repeatAnimation);
}

void MenuInicio::createGameMenu() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Boton para iniciar el juego, situado a un 50% de la altura de la pantalla
	auto buttonNewGame = MenuItemImage::create("GameMenu/003-NewGame.png", "GameMenu/003-NewGame01.png", CC_CALLBACK_1(MenuInicio::newGame, this));
	buttonNewGame->setPosition(Point(visibleSize.width / 2, origin.y + visibleSize.height * 0.57f));
	auto buttonNewGameMenu = Menu::create(buttonNewGame, NULL);
	buttonNewGameMenu->setPosition(Point::ZERO);
	this->addChild(buttonNewGameMenu, 2);

	// Boton de load, situado debajo del boton iniciar
	auto buttonLoadGame = MenuItemImage::create("GameMenu/004-LoadGame.png", "GameMenu/004-LoadGame01.png", CC_CALLBACK_1(MenuInicio::loadGame, this));
	buttonLoadGame->setPosition(Point(buttonNewGame->getPositionX(), buttonNewGame->getPositionY() - buttonNewGame->getContentSize().height - 10));
	auto buttonLoadGameMenu = Menu::create(buttonLoadGame, NULL);
	buttonLoadGameMenu->setPosition(Point::ZERO);
	this->addChild(buttonLoadGameMenu, 2);


	// Boton de opciones, situado debajo del boton anterior
	auto buttonOptions = MenuItemImage::create("GameMenu/005-Options.png", "GameMenu/005-Options01.png", CC_CALLBACK_1(MenuInicio::showOptions, this));
	buttonOptions->setPosition(Point(buttonLoadGame->getPositionX(), buttonLoadGame->getPositionY() - buttonLoadGame->getContentSize().height - 10));
	auto buttonOptionsMenu = Menu::create(buttonOptions, NULL);
	buttonOptionsMenu->setPosition(Point::ZERO);
	this->addChild(buttonOptionsMenu, 2);

	// Boton de Achievements, situado debajo del boton anterior
	auto buttonAchievements = MenuItemImage::create("GameMenu/Achievements01.png", "GameMenu/Achievements02.png", CC_CALLBACK_1(MenuInicio::showAchievements, this));
	buttonAchievements->setPosition(Point(buttonOptions->getPositionX(), buttonOptions->getPositionY() - buttonOptions->getContentSize().height - 10));
	auto buttonAchievementsMenu = Menu::create(buttonAchievements, NULL);
	buttonAchievementsMenu->setPosition(Point::ZERO);
	this->addChild(buttonAchievementsMenu, 2);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX) // Se esta usando al preprocesador para que el boton de exit no se vea en otra plataforma más que en pc
	// Boton de exit, situado debajo del boton anterior (de ultimo)
	auto buttonExit = MenuItemImage::create("GameMenu/006-Exit.png", "GameMenu/006-Exit01.png", CC_CALLBACK_1(MenuInicio::exitGame, this));
	buttonExit->setPosition(Point(buttonAchievements->getPositionX(), buttonAchievements->getPositionY() - buttonAchievements->getContentSize().height - 10));
	auto buttonExitMenu = Menu::create(buttonExit, NULL);
	buttonExitMenu->setPosition(Point::ZERO);
	this->addChild(buttonExitMenu, 1);

#endif

	// Boton de About
	auto buttonAbout = MenuItemImage::create("GameMenu/About01.png", "GameMenu/About02.png", CC_CALLBACK_1(MenuInicio::showAbout, this));
	buttonAbout->setPosition(Point(visibleSize.width / 10, origin.y + visibleSize.height * 0.12f));
	auto buttonAboutMenu = Menu::create(buttonAbout, NULL);
	buttonAboutMenu->setPosition(Point::ZERO);
	this->addChild(buttonAboutMenu, 2);
}

#include "LevelSelectScene.h"
void MenuInicio::newGame(Ref* pSender) {
	//ANIMACIÓN DE PUERTAS
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto animPuertas = Sprite::create("AnimacionPuerta/0001.jpg");
	animPuertas->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(animPuertas, 0);

	auto animation = Animation::create();
	for (int i = 2; i < 6; ++i)
		animation->addSpriteFrameWithFile(String::createWithFormat("AnimacionPuerta/000%i.jpg", i)->getCString());
	animation->setDelayPerUnit(0.10f);
	animPuertas->runAction(Animate::create(animation));
	// FIN DE ANIMACION PUERTAS

	// IMPORTANTE: PREGUNTAR A PROFE COMO VARIAR ESTO PARA QUE EL REPLACESCENE SE CORRA HASTA CONCLUIDA LA ANIMACION
	// DADO QUE SE ESTÁN CORRIENDO CASI QUE DE FORMA SIMULTÁNEA.
	// EN ESTE CASO SE ESTÁ JUGANDO CON EL TIEMPO DE LA CCTRANSITIONFADE (CON ESE 1.60f) Y ASÍ SE ESTÁ LOGRANDO
	// PERO NO ES LO INDICADO (DEBERÍA DE SABERSE CUANDO SE CONLUYE LA ANIMACIÓN PARA CORRER LUEGO EL REPLACESCENE)
	auto newScene = LevelSelectScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionFade::create(1.60f, newScene));
}

void MenuInicio::loadGame(Ref *pSender) {
}

void MenuInicio::showAchievements(Ref *pSender) {
}

#include "OptionsScene.h"
void MenuInicio::showOptions(cocos2d::Ref *pSender) {
	auto newScene = OptionsScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionFade::create(0.60f, newScene));
}

void MenuInicio::exitGame(Ref* pSender) {
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

#include "AboutScene.h"
void MenuInicio::showAbout(Ref *pSender) {
	auto newScene = AboutScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionFade::create(0.60f, newScene));
}