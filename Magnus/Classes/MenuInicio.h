#ifndef __MENU_INICIO_H__
#define __MENU_INICIO_H__

#include "cocos2d.h"

class MenuInicio : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	/// Se invoca cuando el jugador presiona el boton 'nuevo juego'
	void newGame(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton 'cargar juego'
	void loadGame(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton 'Opciones'
	void showOptions(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton 'Trofeos'
	void showAchievements(cocos2d::Ref* pSender);

	// selector para exit
	void exitGame(cocos2d::Ref* pSender);

	// selector para about
	void showAbout(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MenuInicio);

private:
	/// Crea el titulo del juego y lo anima
	void createGameTitle();

	/// Crea las opciones del menu del juego: los botones Iniciar, Premios, Opciones...
	void createGameMenu();
};

#endif // __MENU_INICIO_H__

