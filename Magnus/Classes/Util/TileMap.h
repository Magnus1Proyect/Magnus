#ifndef TiledMap_H
#define TiledMap_H

#include "cocos2d.h"


/**
@brief  This class is going to handle the TileMaps, it deals with the interactions with the TileMap.
*/

class TileMap : public cocos2d::Layer {

	// arbol de nodos al parsear el xml cargado de internet. Después para enviarlo se debe secuenciar y volverlo a parsear de vuelta a xml y enviarlo a internet.
	// random access file por uno mismo o una base de datos. SQlite
protected:
	cocos2d::TMXLayer* background; // background layer
	cocos2d::TMXLayer* foreground;
	cocos2d::TMXLayer* foreground2; // a second layer over the first foreground
	cocos2d::TMXLayer* meta; // Upper layer with the properties
	
	cocos2d::TMXTiledMap* tileMap; // The tilemap handler, we will use this to parse and render the tileMap 
	
	cocos2d::TMXObjectGroup* obstacules; // This will be the objects Tulsi will have to deal with. Example: river
	
	cocos2d::Sprite* player; // Tulsi

	float direction; // We are using this to move the sprite, it will be 10
	
	/**
	* @brief Sets the Point of View using an element as reference.
	* It will handle with view changes, size and kind of map.
	* @param Reference element from which we set the point of view.
	* @param Tilemap we are going to use
	* @return cocos2d::Point
	*/

	virtual cocos2d::Point setPointOfViewCenter(cocos2d::Point elemento);

	/**
	* @brief Handles the events and listen.
	* @param tileMap active.
	*
	*/
	virtual void setEventHandlers(cocos2d::Sprite* player);

	void setPlayerPosition(cocos2d::Point position, cocos2d::Sprite* player);
	/**
	* @brief It loads the .tmx , the tilemap and it properties. We read "load the tilemap" as loading each of its layers, sprites, etc. This is of the .tmx
	* @param mapTmx the .tmx path
	* @param backgroundLayerName layer of .tmx, the background one
	* @param frontLayerName layer of .tmx, the frontLayer one
	* @param frontLayer2Name layer of .tmx. This ones adds depth into the first frontLayer. It is a frontLayer as well.
	* @param metaLayerName the layer we use to deal with properties, the objects with colisision are painted here, such to speak
	* @param objectGroupName container with the tileMap objects
	*/

	virtual void loadMap(const std::string& mapTmx, const std::string& backgroundLayerName, const std::string& frontLayerName
		, const std::string& frontLayer2Name, const std::string& metaLayerName, const std::string& objectContainerName);
	
	/**
	* @brief Returns the coord of the clicked tile.
	* @param position of the tile
	* @param tileMap currently at display
	* @return cocos2d::Point
	*/
	virtual cocos2d::Point tileCoordPosition(cocos2d::Point position);
	/**
	* @brief Checks the properties (meta) of the touched tile
	* He takes the properties, reads them and returns the result.
	* @param Position from which we want the results
	* @param tileMap the active tileMap.
	* @param meta layer where properties are stored.
	* @return cocos2d::Point
	*/
	std::string metaLayerChecker(cocos2d::Point posicion); 

	//virtual void setPlayerPosition(cocos2d::Point position);

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	/**
	* @brief This method listens when a key is pressed and checks if it matches the ones he handles, if so, then it reacts according to that key.
	The first he receives is the keycode from the pressed key, the second one is the event in memory	
	* @param cocos2d::EventKeyboard::KeyCode keycode. 
	* @param cocos2d::Event *event
	*/

	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event, cocos2d::Sprite* player);
	
	virtual void update(cocos2d::Sprite* player, float direction, char axe);

	//void KeyMovement(.....) { }
		
};
#endif // TiledMap_H