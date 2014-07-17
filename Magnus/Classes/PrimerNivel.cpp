
#include "PrimerNivel.h"
#include "MenuInicio.h" // Para poder regresar al menu Inicio.
#include <SimpleAudioEngine.h>

#define COCOS2D_DEBUG 1

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
bool PrimerNivel::init() {
	// 1. super init first
	if (!Layer::init()) { // if there is a mistake then we terminate the program, it couldnt launch 
		return false;
	}

	//auto fileMap = String::createWithContentsOfFile(FileUtils::getInstance()->fullPathForFilename(file.c_str()).c_str());

	loadMap("TileMaps/PrimerNivel.tmx", "Background", "Foreground", "Meta", "Foreground2", "Obstacules");
	loadPlayer();
	metaLayerChecker(Tulsi.getPosition());
	tileMap->addChild(Tulsi.getSprite(), 1);
	this->addChild(tileMap, -1, 1);
	Point View = setPointOfViewCenter(Point (Tulsi.getSprite()->getPositionX(), Tulsi.getSprite() -> getPositionY()));
	tileMap->setPosition(CC_POINT_PIXELS_TO_POINTS(View));
	//tileMap = TMXTiledMap::createWithXML(fileMap->getCString(), "");
	//this->addChild(tileMap, -1); //  http://www.cocos2d-x.org/forums/6/topics/51024
	
	setEventHandlers(Tulsi);

	return true;
}

void PrimerNivel::loadPlayer(){
	//Load the object into the map.
	auto tulsi = obstacules->getObject("Tulsi");
	CCASSERT(!tulsi.empty(), "Tulsi object not found");

	int x = tulsi["x"].asInt(); // probando valores para que este en el mapa, antes habia un +1000 en el otro mapa, averiguar problema y corregirlo
	int y = tulsi["y"].asInt();

	//spriteTulsi = Sprite::create("xD.png");
	Tulsi.loadSprite("ElementalTulsi.png", 0, 0, 48, 48);
	Tulsi.setPosition(x+160,y+16);
		
	setPointOfViewCenter(Tulsi.getPosition());
}

void PrimerNivel::pauseGame() { /// pending
}

void PrimerNivel::resumeGame() { //// pending
}

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