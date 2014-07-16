#ifndef SegundoNivel_h
#define SegundoNivel_h

#include "cocos2d.h"
#include "Player.h" // The player class
#include "Power.h" // Our power class
#include "Util\TileMap.h" // TileMap class we created to deal with those

/**
@brief This is the second level scene, it uses the tileMap
*/

class SegundoNivel : public TileMap { // this is the Second Level Scene with the layer of TileMap

private:
	cocos2d::Sprite *flyingPower;
public:

	Player Tulsi;
	Power Flying;
	Power Freeze;
	//Power Fire;
	//Power   Un vector o lista de poderes la cual se importa

	/**
	@brief    We prepare our scene
	@return instance pointer We return the id (Identification)
	*/
	static cocos2d::Scene* createScene();

	/**
	@brief    The Scene is prepared and created/displayed if everything goes fine
	@return true    Initialize success, program continues.
	@return false   Initialize failed, program terminates.
	*/
	virtual bool init(); /// Se invoca cuando el jugador presiona el boton 'regresar al inicio'

	/**
	@brief If the logo is clicked then we return to the Game Menu
	@param We require the reference of the game menu
	*/
	//void returnGameMenu(cocos2d::Ref* pSender);

	/**
	@brief We create a function, basically we will do a layer above the background, this will allow us to use it.
	@param We need the class type to create the layer.
	*/
	CREATE_FUNC(SegundoNivel);

private:
	/// Crea las opciones del menu, como el icono para regresar al menu del juego
	/**
	@brief We create the Menu so we can go back to it when the logo/home button is clicked. The icon is also created.
	*/
	void createMenu();

	// Jugador, tulsi
	/**
	@brief We bring and set the player Sprite, Tulsi.
	*/
	void loadPlayer();

	/**
	@brief The powers are brought to the map and ready to be grabbed.
	@return bool true if brought correctly
	@return bool false if not.
	*/
	bool loadPowers();

};

#endif // SegundoNivel_h
