#ifndef __MENU_INICIO_H__
#define __MENU_INICIO_H__

#include "cocos2d.h"

/**
@brief    The is the main menu class, here you can choose to play a new game, load a previous one, modify options, check the about window or
your achievements and exit. 
*/

class MenuInicio : public cocos2d::Layer {
public:
	// We return the class instance pointer, its id.
	static cocos2d::Scene* createScene();

	/**
	@brief    The MenuInicio Scene is prepared and created if everything goes fine
	@return true    Initialize success, program continues.
	@return false   Initialize failed, program terminates.
	*/
	virtual bool init();

	/**
	@brief    Its void, what is does is a button so when clicked it will change scene.
	@param   It needs the reference where he will go when clicked
	*/
	/// Se invoca cuando el jugador presiona el boton 'nuevo juego'
	void newGame(cocos2d::Ref* pSender);

	/**
	@brief    Its void, what is does is a button so when clicked it will change scene.
	@param   It needs the reference where he will go when clicked
	*/
	/// Se invoca cuando el jugador presiona el boton 'cargar juego'
	void loadGame(cocos2d::Ref* pSender);

	/**
	@brief    Its void, what is does is a button so when clicked it will change scene.
	@param   It needs the reference where he will go when clicked
	*/
	/// Se invoca cuando el jugador presiona el boton 'Opciones'
	void showOptions(cocos2d::Ref* pSender);

	/**
	@brief    Its void, what is does is a button so when clicked it will change scene.
	@param   It needs the reference where he will go when clicked
	*/
	/// Se invoca cuando el jugador presiona el boton 'Trofeos'
	void showAchievements(cocos2d::Ref* pSender);

	/**
	@brief    Its void, what is does is a button so when clicked it will end the program
	@param   It needs the reference where he will go when clicked, in this case he will exit
	*/
	// selector para exit
	void exitGame(cocos2d::Ref* pSender);

	/**
	@brief    Its void, what is does is a button so when clicked it will change scene.
	@param   It needs the reference where he will go when clicked
	*/
	// selector para about
	void showAbout(cocos2d::Ref* pSender);

	/**
	@brief We create a function, basically we will do a layer above the background, this will allow us to use it.
	@param We need the class type to create the layer.
	*/
	CREATE_FUNC(MenuInicio);

private:
	/**
	@brief We create the Game Tittle and animate it.
	*/
	void createGameTitle(); /// We create the game title and animate it, it doesnt return anything, it just creates it.

	/**
	@brief We create the Game Menu, each option/botton Iniciar, Premios, Opciones...
	*/
	void createGameMenu();
};

#endif // __MENU_INICIO_H__

