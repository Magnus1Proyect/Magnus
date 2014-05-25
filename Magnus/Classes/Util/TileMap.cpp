#include "TileMap.h"

USING_NS_CC;

Point TileMap::setPointOfViewCenter(cocos2d::Point element) { // element would be the player itself
	cocos2d::Size winSize = Director::getInstance()->getWinSize();

	int x = MAX(element.x, winSize.width / 2);
	int y = MAX(element.y, winSize.height / 2);
	x = MIN(x, (tileMap->getContentSize().width * this->tileMap->getContentSize().width) - winSize.width / 2);
	y = MIN(y, (tileMap->getContentSize().height * this->tileMap->getContentSize().height) - winSize.height / 2);

	cocos2d::Point actualPosition = Point(x, y);
	cocos2d::Point centerOfView = Point(winSize.width / 2, winSize.height / 2);
	cocos2d::Point viewPoint = centerOfView - actualPosition; // ccp(actual.x - center.x, actual.y - center.y); deprecated
	return viewPoint;
}


void TileMap::setEventHandlers(){
	//Create a "one by one" touch event listener (processes one touch at a time)
	auto listener = EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	listener->setSwallowTouches(true);

	// Example of using a lambda expression to implement onTouchBegan event callback function
	
	//listener->onTouchBegan = CC_CALLBACK_2(ChainReactionScene::placeExplosion, this);

	//Add listener
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
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

