#ifndef TiledMap_H
#define TiledMap_H

#include "cocos2d.h"
#include "Player.h"

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

	

	//float direction; // We are using this to move the sprite, it will be 10
	
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
	* @param cocos2d::Sprite* The sprite of Tulsi in this case.
	*/
	virtual void setEventHandlers(Player player);

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
		, const std::string& metaLayerName, const std::string& frontLayer2Name, const std::string& objectContainerName);

	/**
	* @brief 
	* @param cocos2d::Point position, its the x and y we are sending, its the Point in the map where
	we want our player.
	* @param cocos2d:Sprite* player, we send the pointer to the player.
	*/
	virtual void setPlayerPosition(cocos2d::Point position, Player player);
	
	/**
	* @brief Checks the properties (meta) of the touched tile
	* He takes the properties, reads them and returns the result.
	* @param Position from which we want the results
	* @param tileMap the active tileMap.
	* @param meta layer where properties are stored.
	* @return cocos2d::Point
	*/
	std::string metaLayerChecker(cocos2d::Point posicion);

	//Changer
	void LayerChanger(cocos2d::Point posicion, std::string value);

	/**
	* @brief Returns the coord of the clicked tile.
	* @param position of the tile
	* @return cocos2d::Point
	*/

	virtual cocos2d::Point tileCoordPosition(cocos2d::Point position);

	/**
	* @brief This method listens when a key is pressed.
	We are listening to the pressed key but we only do something when it is released. The method doing so is keyPressed()
	* @param cocos2d::EventKeyboard::KeyCode keycode.
	* @param cocos2d::Event *event
	*/
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	/**
	* @brief This method listens when a key is released and checks if it matches the ones he handles, if so, then it reacts according to that key.
	The first he receives is the keycode from the pressed key, the second one is the event in memory and the third is the reference sprite player.
	* @param cocos2d::EventKeyboard::KeyCode keycode.
	* @param cocos2d::Event *event
	* @param cocos2d::Sprite* player
	*/

	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event, Player player);
	
	/**
	* @brief Este metodo va a refrescar la vista despues de cada keyreleased, ahi es llamado. También llamará el

	Lo que va a hacer es ver la posicion inicial del personaje y actuar acorde a lo que reciba.
	Lo que va a recibir son los int que representan el cambio en las coordenadas.
	Ejemplo: Si es un w significa que va para arriba, en teoría se movería a la pos columna, fila+1
	http://wenku.baidu.com/view/ade69359be23482fb4da4c44.html
	http://www.cocos2d-x.org/forums/6/topics/22892
	*/
	virtual void update(cocos2d::Sprite* player, float direction, char axe);

	//void KeyMovement(.....) { }

	void TileMap::applyPower(float x, float y, Player player);

	void TileMap::loadPowers(cocos2d::Point position, Player player, std::string pathAhead);
		
};
#endif // TiledMap_H