#include "TileMap.h"

USING_NS_CC;

Point TileMap::setPointOfViewCenter(cocos2d::Point element) { // element would be the player itself
	cocos2d::Size winSize = Director::getInstance()->getWinSize();

	int x = MAX(element.x, winSize.width / 2);
	int y = MAX(element.y, winSize.height / 2);
	x = MIN(x, (tileMap->getContentSize().width* this->tileMap->getContentSize().width) - winSize.width / 2);
	y = MIN(y, (tileMap->getContentSize().height* this->tileMap->getContentSize().height) - winSize.height / 2);

	cocos2d::Point actualPosition = Point(x, y);
	cocos2d::Point centerOfView = Point(winSize.width / 2, winSize.height / 2);
	cocos2d::Point viewPoint = centerOfView - actualPosition; // ccp(actual.x - center.x, actual.y - center.y); deprecated
	return viewPoint;
}


void TileMap::setEventHandlers(Sprite* player){
	//Create an event listener. It will listen to the keyboard input.
	auto keyboardListener = EventListenerKeyboard::create();
	
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	//listener->setSwallowTouches(true);
	
	// The method who handles when a key is pressed. 
	keyboardListener->onKeyPressed = CC_CALLBACK_2(TileMap::keyPressed, this);
	// The method who handles when a key is released. We are using this as the one who actually does something
	keyboardListener->onKeyReleased = CC_CALLBACK_2(TileMap::keyReleased, this, player);

	//Add listener
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void TileMap::setPlayerPosition(Point position, cocos2d::Sprite* player)
{
	Point tileCoord = this->tileCoordPosition(position);
	int tileGid = meta->getTileGIDAt(tileCoord);
	if (tileGid) {
		auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
		if (!properties.empty()) {
			auto collision = properties["Blockage"].asString();
			if ("true" == collision) {
				log("Blocked");
				return;
			}
			else if ("mid" == collision){
				log("Water");
			}
			else if ("false" == collision)
			{
				player->setPosition(position);
				log(player->getPositionX());
				log("nomnom");
			}
		}
	}
	
}

void TileMap::loadMap(const std::string& mapFile, const std::string& backgroundLayerName, const std::string& frontLayerName,
	const std::string& frontLayer2Name, const std::string& metaLayerName, const std::string& objectContainerName) {
	tileMap = TMXTiledMap::create(mapFile);
	CCAssert(tileMap != nullptr, "'mapFile' map not found");
	tileMap->setAnchorPoint(Point(0.0f, 0.0f));
	background = tileMap->getLayer(backgroundLayerName);
	CCAssert(background != nullptr, "'backgroundLayerName' not found");
	foreground = tileMap->getLayer(frontLayerName);
	CCAssert(foreground != nullptr, "'frontLayerName' not found");
	foreground2 = tileMap->getLayer(frontLayer2Name);
	CCAssert(foreground2 != nullptr, "'frontLayer2Name' not found");
	meta = tileMap->getLayer(metaLayerName);
	meta->setVisible(false);
	CCAssert(meta != nullptr, "'metaLayerName' not found");
	obstacules = tileMap->getObjectGroup(objectContainerName);
	CCAssert(obstacules != nullptr, "'obstacules' object container not found");
}


Point TileMap::tileCoordPosition(Point position) {
	int x = position.x / tileMap->getTileSize().width;
	int y = ((tileMap->getMapSize().height * tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;


	Size tileSize = tileMap->getTileSize();
	Size mapSize = tileMap->getMapSize();

	return Point(x, y);

}

void TileMap::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event) {
	//put this inside keyPressed or keyReleased
	if (keyCode == EventKeyboard::KeyCode::KEY_W) 	{ // north, up
		log("W key was pressed");
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S) 	{ // south, down
		log("S key was pressed");
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_D) 	{ // right
		log("D key was pressed");
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_A) 	{ // left
		log("A key was pressed");
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_Q) 	{ // power
		log("Q key was pressed");
	}
	
}

void TileMap::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event, cocos2d::Sprite* player) {
	int xx = player->getPositionX();
	int yy = player->getPositionY();

	if (keyCode == EventKeyboard::KeyCode::KEY_W) 	{
		log("W key was pressed");
		this->setPlayerPosition(Point(xx+32,yy+16), player);
		//this->update(player, 10.0f, 'y'); // por ahora se usará el 10, después se trabajará en agregarle una variable relativa al tamano del mapa o el tile
		
		// movimiento aqui. Metodo por aparte
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S) 	{ // south, down
		log("S key was pressed");
		this->setPlayerPosition(Point(xx-32,yy-16), player);
		//this->update(player, -10.0f, 'y');
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_D) 	{ // right
		log("D key was pressed");
		this->setPlayerPosition(Point(xx + 32, yy -16), player);
		//this->update(player, 10.0f, 'x');
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_A) 	{ // left
		log("A key was pressed");
		this->setPlayerPosition(Point(xx - 32, yy + 16),  player);
		//this->update(player, -10.0f, 'x');
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_Q) 	{ // power
		log("Q key was pressed");
	}
	// Se traduce: arriba es +10, abajo es -10, a la derecha es +10 a la x, a la izquierda es -10 a la x
}
	
void TileMap::update(cocos2d::Sprite* player, float direction, char axe){

	if (axe == 'y'){ // if we need to move the y
		player->setPositionY(player->getPositionY() + direction);//, player->setPositionY(player->getPositionY() + 1);
	}
	else if (axe == 'x'){ // if we need to move the x
		player->setPositionX(player->getPositionX() + direction);//, player->setPositionY(player->getPositionY() + 1);
	}
	
	
		/**
	* @brief Este metodo va a refrescar la vista despues de cada keyreleased, ahi es llamado.
	
	Lo que va a hacer es ver la posicion inicial del personaje y actuar acorde a lo que reciba. 
	Lo que va a recibir son los int que representan el cambio en las coordenadas. 
	Ejemplo: Si es un w significa que va para arriba, en teoría se movería a la pos columna, fila+1
	http://wenku.baidu.com/view/ade69359be23482fb4da4c44.html
	http://www.cocos2d-x.org/forums/6/topics/22892
	*/
	
	}



std::string TileMap::metaLayerChecker(Point position) {
	std::string result = "";
	Point tileCoord = this->tileCoordPosition(position);
	int tileGid = meta->tileGIDAt(tileCoord);
	if (tileGid) {
		Value properties = tileMap->getPropertiesForGID(tileGid);
		auto property = properties.asValueMap();
		auto p = property["collision"].asString();

		if (p.compare("collision") == 0) {
			log("collision");
			result = "collision";
		}
	}
	return result;
}

