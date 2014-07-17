#ifndef LevelSelectScene_h
#define LevelSelectScene_h

#include "cocos2d.h"

/**
@brief    This the window where you load or select the level you want to play, this unlocks as you advance through the story/game.
*/

class LevelSelectScene : public cocos2d::Layer { // this is the Load Game Scene
public:
	/**
	@brief    We prepare our scene
	@return instance pointer We return the id (Identification)
	*/
	static cocos2d::Scene* createScene();

	/**
	@brief    The Load Game Scene is prepared and created/displayed if everything goes fine
	@return true    Initialize success, program continues.
	@return false   Initialize failed, program terminates.
	*/
	virtual bool init(); /// Se invoca cuando el jugador presiona el boton 'regresar al inicio'

	/**
	@brief If the logo is clicked then we return to the Game Menu
	@param We require the reference of the game menu
	*/
	void returnGameMenu(cocos2d::Ref* pSender);

	/**
	@brief If the logo is clicked then we go to Primer Nivel.
	@param We require the reference of the Primer Nivel
	*/
	void goToFirstLevel(cocos2d::Ref* pSender);

	/**
	@brief If the logo is clicked then we go to Segundo Nivel.
	@param We require the reference of the Segund Nivel
	*/
	void goToSecondLevel(cocos2d::Ref* pSender);

	/**
	@brief We create a function, basically we will do a layer above the background, this will allow us to use it.
	@param We need the class type to create the layer.
	*/
	CREATE_FUNC(LevelSelectScene);

private:
	/// Crea las opciones del menu, como el icono para regresar al menu del juego
	/**
	@brief We create the Menu so we can go back to it when the logo/home button is clicked. The icon is also created.
	*/
	void createMenu();
};

#endif // LevelSelectScene_h
