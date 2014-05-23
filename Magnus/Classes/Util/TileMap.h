#ifndef TiledMap_H
#define TiledMap_H

#include "cocos2d.h"

/**
@brief    This class is the class who we plan will handle the TileMaps, it deals with the interactions with the TileMap.
*/

class TileMap : public cocos2d::Layer {

	// arbol de nodos al parsear el xml cargado de internet. Después para enviarlo se debe secuenciar y volverlo a parsear de vuelta a xml y enviarlo a internet.
	// random access file por uno mismo o una base de datos. SQlite
protected:
	cocos2d::TMXLayer* background;
	cocos2d::TMXLayer* foreground;
	cocos2d::TMXLayer* meta; // Upper layer
	
	cocos2d::TMXTiledMap* tileMap; // The tilemap handler, we will use this to parse and render the tileMap 
	
	cocos2d::TMXObjectGroup* obstacules; // This will be the objects Tulsi will have to deal with. Example: river
	
	cocos2d::Sprite* player; // Tulsi
	
	/**
	* @brief Sets the Point of View using an element as reference.
	* It will handle with view changes, size and kind of map.
	* @param Reference element from which we set the point of view.
	* @param Tilemap we are going to use
	* @return cocos2d::Point
	*/

	virtual cocos2d::Point setPointOfView(cocos2d::Point elemento);

	/**
	* @brief Handles the events and listen
	* @param tileMap active.
	*
	*/
	virtual void setEventHandlers();
	/**
	* @brief It loads the .tmx , the tilemap and it properties
	* @param mapTmx the .tmx path

	* @param metaLayerName the layer we use to deal with properties
	* @param objectGroupName container with the tileMap objects
	*/

	virtual void loadMap(const std::string& mapTmx, const std::string& backgroundLayerName, const std::string& frontLayerName
		, const std::string& metaLayerName, const std::string& objectContainerName);
	
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
	std::string metaLayerChecker(cocos2d::Point posicion); \
		
};
#endif // TiledMap_H