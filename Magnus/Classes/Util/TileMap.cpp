#include "TileMap.h"
#include "PowerList.h"

USING_NS_CC;

//POWERS LIST
PowerList powers;

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

void TileMap::setEventHandlers(Player player){
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

void TileMap::loadMap(const std::string& mapFile, const std::string& backgroundLayerName, const std::string& frontLayerName,
	const std::string& metaLayerName, const std::string& frontLayer2Name, const std::string& objectContainerName) {
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

void TileMap::setPlayerPosition(Point position, Player player) {
	std::string pathAhead = this->metaLayerChecker(position);
	
	if (pathAhead == "Edge") {
		log("Stoped by the Edge of the map");
	}
	else if ((pathAhead == "Solid") && (player.getPower().getSolid() == false)) {
		log("Stoped by Solid");
	}
	else if ((pathAhead == "Water") && (player.getPower().getWater()==false)) {
		log("Stoped by Water");
	}
	else if ((pathAhead == "Ice") && (player.getPower().getIce() == false)) {
		log("Stoped by Ice");
	}
	else if ((pathAhead == "Fire") && (player.getPower().getFire() == false)) {
		log("Stoped by Fire");
	}
	else{

		player.setPosition(position);
		if (pathAhead == "flyPower") {
			LayerChanger(position, "power");
			player.setPower(powers.Fly());
		}
		else if (pathAhead == "icePower") {
			LayerChanger(position, "power");
			player.setPower(powers.Icepower());
		}
		else if (pathAhead == "firePower") {
			LayerChanger(position, "power");
			player.setPower(powers.Fireproof());
		}
		else if (pathAhead == "waterPower") {
			LayerChanger(position, "power");
			player.setPower(powers.Swim());
		}
		else if (pathAhead == "firePower") {
			LayerChanger(position, "power");
			player.setPower(powers.Fireproof());
		}
		else if (pathAhead == "ghostPower") {
			LayerChanger(position, "power");
			player.setPower(powers.Ghost());
		}
	}
}

std::string TileMap::metaLayerChecker(Point position) {
	std::string result = ""; // no colisiona
	Point tileCoord = this->tileCoordPosition(position); // Aqui esta el problema, tenemos otro tile
	int tileGid = meta->tileGIDAt(tileCoord);
		if (tileGid) {
			//Value properties = tileMap->getPropertiesForGID(tileGid); Se decidió hacer en una sola línea
			auto properties = tileMap->getPropertiesForGID(tileGid).asValueMap();
			if (!properties.empty()) {
				result = properties["Blockage"].asString();
			}
		}
	return result;
}

void TileMap::LayerChanger(Point position, std::string value) {
	std::string pathAhead = this->metaLayerChecker(position);
	if (value == "power"){
		//ChangeMeta
		Point tileCoord = this->tileCoordPosition(position);
		auto tileSet = meta->getTileSet();
		int newGID = (tileSet->_firstGid) + 8;
		meta->setTileGID(newGID, tileCoord);
		//ChangeForeground1
		tileSet = foreground->getTileSet();
		foreground->removeTileAt(tileCoord);
	}
	if ((value == "Ice")&&(pathAhead=="Water")){
		//ChangeMeta
		Point tileCoord = this->tileCoordPosition(position);
		auto tileSet = meta->getTileSet();
		int newGID = (tileSet->_firstGid) + 8;
		meta->setTileGID(newGID, tileCoord);
		//ChangeBackground
		tileSet = background->getTileSet();
		newGID = (background->getTileGIDAt(tileCoord))+26;
		background->setTileGID(newGID, tileCoord);
	}
}

Point TileMap::tileCoordPosition(Point position) {
	int x = position.x / tileMap->getTileSize().width;
	int y = ((tileMap->getMapSize().height * tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;

	Size tileSize = tileMap->getTileSize();
	Size mapSize = tileMap->getMapSize();

	log("x" + x);
	log("y" + y);

	float halfMapWidth = mapSize.width * 0.5f;
	float mapHeight = tileMap->getMapSize().width;
	float tileWidth = tileMap->getTileSize().width  / CC_CONTENT_SCALE_FACTOR();
	float tileHeight = tileMap->getTileSize().height  / CC_CONTENT_SCALE_FACTOR();

	Point tilePosDiv = Point(position.x / tileWidth, position.y / tileHeight);
	float mapHeightDiff = mapHeight - tilePosDiv.y;

	int posX = (mapHeightDiff + tilePosDiv.x - halfMapWidth);
	int posY = (mapHeightDiff - tilePosDiv.x + halfMapWidth);

	return Point(posX, posY);
	}

void TileMap::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event) {
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

void TileMap::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event, Player player) {
	int xx = player.getSprite()->getPositionX();
	int yy = player.getSprite()->getPositionY();

	if (keyCode == EventKeyboard::KeyCode::KEY_W) 	{
		log("W key was released");
		this->setPlayerPosition(Point(xx+32,yy+16), player);
		//this->update(player, 10.0f, 'y'); // por ahora se usará el 10, después se trabajará en agregarle una variable relativa al tamano del mapa o el tile
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S) 	{ // south, down
		log("S key was released");
		this->setPlayerPosition(Point(xx-32,yy-16), player);
		//this->update(player, -10.0f, 'y');
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_D) 	{ // right
		log("D key was released");
		this->setPlayerPosition(Point(xx + 32, yy -16), player);
		//this->update(player, 10.0f, 'x');
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_A) 	{ // left
		log("A key was released");
		this->setPlayerPosition(Point(xx - 32, yy + 16),  player);
		//this->update(player, -10.0f, 'x');
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_Q) 	{ // power
		log("Q key was released");
	}
	// Se traduce: arriba es +10, abajo es -10, a la derecha es +10 a la x, a la izquierda es -10 a la x

	if (keyCode == EventKeyboard::KeyCode::KEY_P) 	{ // power
		this->applyPower(xx, yy, player);
		log("P key was pressed");
	}
}

void TileMap::applyPower(float x, float y, Player player){
	if (player.getPower().getName() == "Icepower"){
		log("Icepower activated");
		LayerChanger(Point(x + 32, y - 16), "Ice");
		LayerChanger(Point(x + 32, y + 16), "Ice");
		LayerChanger(Point(x,y), "Ice");
		LayerChanger(Point(x - 32, y + 16), "Ice");
		LayerChanger(Point(x - 32, y - 16), "Ice");
	}
}
	
void TileMap::update(cocos2d::Sprite* player, float direction, char axe){

	if (axe == 'y'){ // if we need to move the y
		player->setPositionY(player->getPositionY() + direction);//, player->setPositionY(player->getPositionY() + 1);
	}
	else if (axe == 'x'){ // if we need to move the x
		player->setPositionX(player->getPositionX() + direction);//, player->setPositionY(player->getPositionY() + 1);
	}
}



