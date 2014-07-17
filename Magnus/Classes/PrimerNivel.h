#ifndef PrimerNivel_h
#define PrimerNivel_h

#include "cocos2d.h"
#include "Player.h"
#include "Util\TileMap.h" // TileMap class we created to deal with those

/**
@brief This is the first level scene, it uses the tileMap
*/

class PrimerNivel : public TileMap { // this is the First Level Scene with the layer of TileMap

public:

	Player Tulsi;

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
	CREATE_FUNC(PrimerNivel);

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
	@brief This pauses the game
	*/
	void pauseGame();
	/**
	@brief This resumes the game
	*/
	void resumeGame();

};

#endif // PrimerNivel_h
