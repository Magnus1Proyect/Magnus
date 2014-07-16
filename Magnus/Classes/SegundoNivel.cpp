
#include "SegundoNivel.h"
#include "MenuInicio.h" // Para poder regresar al menu Inicio.
#include <SimpleAudioEngine.h>

#define COCOS2D_DEBUG 1

USING_NS_CC;

Scene* SegundoNivel::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SegundoNivel::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SegundoNivel::init() {
	// 1. super init first
	if (!Layer::init()) { // if there is a mistake then we terminate the program, it couldnt launch 
		return false;
	}

	//auto fileMap = String::createWithContentsOfFile(FileUtils::getInstance()->fullPathForFilename(file.c_str()).c_str());

	loadMap("TileMaps/SegundoNivel.tmx", "Background", "Foreground", "Meta", "Foreground2", "Obstacules");
	loadPlayer();
	metaLayerChecker(Tulsi.getPosition());
	tileMap->addChild(Tulsi.getSprite(), 1);
	//this->addChild(tileMap, -1, 1); prueba
	Point View = setPointOfViewCenter(Point (Tulsi.getSprite()->getPositionX(), Tulsi.getSprite() -> getPositionY()));
	loadPowers();
	//tileMap->addChild(Flying.getSprite()); //no encontr� getFlying
	tileMap->addChild(Flying.getSprite());
	this->addChild(tileMap, -1, 1);
	tileMap->setPosition(CC_POINT_PIXELS_TO_POINTS(View));
	//tileMap = TMXTiledMap::createWithXML(fileMap->getCString(), "");
	//this->addChild(tileMap, -1); //  http://www.cocos2d-x.org/forums/6/topics/51024
	
	setEventHandlers(Tulsi);

	return true;
}

void SegundoNivel::loadPlayer(){
	//Load the object into the map.
	auto tulsi = obstacules->getObject("Tulsi");
	CCASSERT(!tulsi.empty(), "Tulsi object not found");

	int x = tulsi["x"].asInt(); // probando valores para que este en el mapa, antes habia un +1000 en el otro mapa, averiguar problema y corregirlo
	int y = tulsi["y"].asInt();

	//spriteTulsi = Sprite::create("xD.png");
	Tulsi.loadSprite("tulsi.png", 0, 0, 45, 45);
	Tulsi.setPosition(x+160,y+16);

		
	setPointOfViewCenter(Tulsi.getPosition());
}

bool SegundoNivel::loadPowers(){
	//Load the object into the map.
	auto flying = obstacules->getObject("Flying");
	CCASSERT(!flying.empty(), "Flying power not found");

	int x = flying["x"].asInt(); // probando valores para que este en el mapa, antes habia un +1000 en el otro mapa, averiguar problema y corregirlo
	int y = flying["y"].asInt();

	Flying.loadSprite("flyingPower.png");
	Flying.setPosition(x, y-200);
	return true;
}

//void PrimerNivel::returnGameMenu(Ref* pSender) {
	//auto newScene = MenuInicio::createScene();
	//Director::getInstance()->replaceScene(CCTransitionFade::create(0.60f, newScene));
// Importante Idea de crear clase @crearNiveles, seria una clase de donde se heredan los niveles, es hija de Tilemaps.
//}