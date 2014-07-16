#include "OptionsScene.h" // where we guys talk about ourselves and this important game
#include <SimpleAudioEngine.h> // well we need some music, this helps... its the engine

USING_NS_CC;

Scene* OptionsScene::createScene() {
	// 'scene' is an autorelease object, its the space where the action happens.
	auto scene = Scene::create();

	// 'layer' is an autorelease object, each layer represents stages of the action.
	auto layer = OptionsScene::create();

	// add layer as a child to scene. Lets see it like a tree, action.
	scene->addChild(layer);

	// return the scene. We put the scene back and now its alive
	return scene;
}

// We  initialize our instance
bool OptionsScene::init() {
	// 1. super init first
	if (!Layer::init()) { // if there is a mistake then we terminate the program, it couldnt launch
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// add a label shows "Creditos"
	// create and initialize a label

	auto labelTitulo = LabelTTF::create("Opciones", "Tahoma", 32);

	// position the label on the upper center of the screen
	labelTitulo->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .88f));

	// add the label as a child to this layer
	this->addChild(labelTitulo, 1);

	// We add the devs labels
	auto labelSubtitulo = LabelTTF::create("Desarrolladores", "'Book Antigua", 24);
	labelSubtitulo->setPosition(Point(origin.x + visibleSize.width * 0.25f, origin.y + visibleSize.height * .78f));
	this->addChild(labelSubtitulo, 1);

	auto labelDev1 = LabelTTF::create("Gabriel Coto Barquero", "'Book Antigua", 18);
	labelDev1->setPosition(Point(origin.x + visibleSize.width * 0.50f, origin.y + visibleSize.height * .72f));
	this->addChild(labelDev1, 1);

	auto labelDev2 = LabelTTF::create("Kenneth Fonseca Mendez", "'Book Antigua", 18);
	labelDev2->setPosition(Point(origin.x + visibleSize.width * 0.50f, origin.y + visibleSize.height * .66f));
	this->addChild(labelDev2, 1);

	auto labelDev3 = LabelTTF::create("William Soto Martinez", "'Book Antigua", 18);
	labelDev3->setPosition(Point(origin.x + visibleSize.width * 0.50f, origin.y + visibleSize.height * .60f));
	this->addChild(labelDev3, 1);

	// Creates the background of the game menu.
	auto sprite = Sprite::create("GameMenu/0000.jpg"); // sprites are important, those are the images

	// position the sprite on the center of the screen
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	createMenu(); // We bring to live this scene.

	// Reproducir la musica de la seleccion del nivel: quiza sea mejor dejar la misma del menu
	// principal y cambiarla cuando se haya iniciado el nivel. Se deja aqui por propositos
	// ilustrativos
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic(); // this steps are to change tracks.
	sound->playBackgroundMusic("Music/Options.mp3", true); // We use a piece of music we already have and reproduce it for the options scene.

	return true; // we managed to bring frankestein alive, I mean, the game.
}

void OptionsScene::createMenu() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// We create a botton and show it in screen so we can return to the game menu, its going to be at the upper left corner. 
	auto buttonHome = MenuItemImage::create("000-Logo.png", "000-Logo.png", CC_CALLBACK_1(OptionsScene::returnGameMenu, this));
	buttonHome->setPosition(Point(origin.x + buttonHome->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - buttonHome->getContentSize().height / 2.0f - 5.0f));
	auto buttonHomeMenu = Menu::create(buttonHome, NULL); //aka home is done
	buttonHomeMenu->setPosition(Point::ZERO);
	this->addChild(buttonHomeMenu, 2);
}

#include "MenuInicio.h" // We include the big piece, mister menu, so we can return to him when we click the logo in the About Scene
void OptionsScene::returnGameMenu(Ref* pSender) {
	auto newScene = MenuInicio::createScene(); // We create the scene we are going to use to replace the one that is active
	Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5f, newScene)); //we change the scene by flipping back to the menu.
}
