
#include "PrimerNivel.h"
#include "MenuInicio.h" // Para poder regresar al menu Inicio.
#include <SimpleAudioEngine.h>


USING_NS_CC;


Scene* PrimerNivel::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PrimerNivel::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
//bool PrimerNivel::init() {
	// 1. super init first
	//if (!Layer::init()) { // if there is a mistake then we terminate the program, it couldnt launch
		//return false;
	//}

	//this->addChild(_tileMap);

	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Point origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////

	// add a label shows "Menu Inicio"
	// create and initialize a label

	//auto label = LabelTTF::create("Seleccionar nivel", "Arial", 24);

	// position the label on the center of the screen
//	label->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .64f));

	// add the label as a child to this layer
	//this->addChild(label, 1);

	// Crear el fondo del menu del juego
	//auto sprite = Sprite::create("GameMenu/0000.jpg");

	// position the sprite on the center of the screen
	//sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	//this->addChild(sprite, 0);

	//createMenu();

	// Reproducir la musica de la seleccion del nivel: quiza sea mejor dejar la misma del menu
	// principal y cambiarla cuando se haya iniciado el nivel. Se deja aqui por propositos
	// ilustrativos
	//auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	//sound->stopBackgroundMusic();
	//sound->playBackgroundMusic("Music/LevelSelect.mp3", true);

	//return true;
//}

//void PrimerNivel::createMenu() {
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Point origin = Director::getInstance()->getVisibleOrigin();

	// Boton Logo, para retornar al menu del juego, ubicado en la esquina superior izquierda (cambiar segunda imagen)
	//auto buttonHome = MenuItemImage::create("000-Logo.png", "000-Logo.png", CC_CALLBACK_1(PrimerNivel::returnGameMenu, this));
	//buttonHome->setPosition(Point(origin.x + buttonHome->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - buttonHome->getContentSize().height / 2.0f - 5.0f));
	//auto buttonHomeMenu = Menu::create(buttonHome, NULL);
	//buttonHomeMenu->setPosition(Point::ZERO);
	//this->addChild(buttonHomeMenu, 2);
//}


//void PrimerNivel::returnGameMenu(Ref* pSender) {
	//auto newScene = MenuInicio::createScene();
	//Director::getInstance()->replaceScene(CCTransitionFade::create(0.60f, newScene));
//}