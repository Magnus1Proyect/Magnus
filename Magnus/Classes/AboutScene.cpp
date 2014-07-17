#include "AboutScene.h" // where we guys talk about ourselves and this important game
#include <SimpleAudioEngine.h> // well we need some music, this helps... its the engine

USING_NS_CC;

Scene* AboutScene::createScene() {

	// 'scene' is an autorelease object, its the space where the action happens.
	auto scene = Scene::create();

	// 'layer' is an autorelease object, each layer represents stages of the action.
	auto layer = AboutScene::create();

	// add layer as a child to scene. Lets see it like a tree, action.
	scene->addChild(layer);

	// return the scene. We put the scene back and now its alive
	return scene;
}

// We  initialize our instance
bool AboutScene::init() {
	// 1. super init first
	if (!Layer::init()) { // if there is a mistake then we terminate the program, it couldnt launch
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// add a label shows "Creditos"
	// create and initialize a label
	auto label1 = LabelTTF::create("Creditos", "Book Antigua", 50);
	auto label2 = LabelTTF::create("Programacion", "Book Antigua", 30);
	auto label3 = LabelTTF::create("Gabriel Coto Barquero", "Book Antigua", 20);
	auto label4 = LabelTTF::create("Kenneth Fonseca Mendez", "Book Antigua", 20);
	auto label5 = LabelTTF::create("William Soto Martinez", "Book Antigua", 20);
	auto label7 = LabelTTF::create("Graficos", "Book Antigua", 30);
	auto label8 = LabelTTF::create("Alas....Elturquitokpo", "Book Antigua", 20);
	auto label9 = LabelTTF::create("Puerta de menu....Elizabeth Gallagher", "Book Antigua", 20);
	auto label10 = LabelTTF::create("Puerta de niveles....YoToArt", "Book Antigua", 20);
	auto label11 = LabelTTF::create("Espada....Vecto2000", "Book Antigua", 20);
	auto label12 = LabelTTF::create("Tulsi....Radomir Dopieralski", "Book Antigua", 20);
	auto label13 = LabelTTF::create("Tileset....William Soto", "Book Antigua", 20);

	// position the label on the center of the screen
	label1->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .72f));
	label2->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .60f));
	label3->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .56f));
	label4->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .52f));
	label5->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .48f));
	label7->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .36f));
	label8->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .32f));
	label9->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .28f));
	label10->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .24f));
	label11->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .20f));
	label12->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .16f));
	label13->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .12f));
	// add the label as a child to this layer
	this->addChild(label1, 1);
	this->addChild(label2, 1);
	this->addChild(label3, 1);
	this->addChild(label4, 1);
	this->addChild(label5, 1);
	this->addChild(label7, 1);
	this->addChild(label8, 1);
	this->addChild(label9, 1);
	this->addChild(label10, 1);
	this->addChild(label11, 1);
	this->addChild(label12, 1);
	this->addChild(label13, 1);

	// Creates the background of the game menu.
	auto sprite = Sprite::create("GameMenu/0000.jpg"); // sprites are important, those are the images

	// position the sprite on the center of the screen
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	createMenu(); // We bring to live this scene.

	// We change the music
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic(); // this steps are to change tracks.
	sound->playBackgroundMusic("Music/About.mp3", true); // We use a piece of music we already have and reproduce it for the about scene.

	return true; // we managed to bring frankestein alive, I mean, the game.
}

void AboutScene::createMenu() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// We create a botton and show it in screen so we can return to the game menu, its going to be at the upper left corner. 
	auto buttonHome = MenuItemImage::create("000-Logo.png", "000-Logo.png", CC_CALLBACK_1(AboutScene::returnGameMenu, this));
	buttonHome->setPosition(Point(origin.x + buttonHome->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - buttonHome->getContentSize().height / 2.0f - 5.0f));
	auto buttonHomeMenu = Menu::create(buttonHome, NULL); //aka home is done
	buttonHomeMenu->setPosition(Point::ZERO);
	this->addChild(buttonHomeMenu, 2);
}

#include "MenuInicio.h" // We include the big piece, mister menu, so we can return to him when we click the logo in the About Scene
void AboutScene::returnGameMenu(Ref* pSender) {
	auto newScene = MenuInicio::createScene(); // We create the scene we are going to use to replace the one that is active
	Director::getInstance()->replaceScene(CCTransitionFade::create(0.60f, newScene)); // we change the screen and we use a fading transition
}
