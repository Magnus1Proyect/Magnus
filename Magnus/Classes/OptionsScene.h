#ifndef OptionsScene_h
#define OptionsScene_h

#include "cocos2d.h"

/**
@brief  Here you modify the options so you can enjoy more the game
*/

class OptionsScene : public cocos2d::Layer {
public:

	/**
	@brief    We prepare our scene
	@return instance pointer We return the id (Identification)
	*/
	
	static cocos2d::Scene* createScene(); //We return the class instance pointer, its id

	/**
	@brief   Options Scene is prepared and created/displayed if everything goes fine
	@return true    Initialize success, program continues.
	@return false   Initialize failed, program terminates.
	*/
	virtual bool init(); /// We call this when the player hit the "regresar al inicio", what it does is return to the front, the menu
	
	/**
	@brief If the logo is clicked then we return to the Game Menu
	@param reference We require the reference of the game menu
	*/
	void returnGameMenu(cocos2d::Ref* pSender);

	/**
	@brief We create a function, basically we will do a layer above the background, this will allow us to use it.
	@param class type We need the class type to create the layer.
	*/
	CREATE_FUNC(OptionsScene);

private: 
	/**
	@brief We create the Menu so we can go back to it when the logo/home button is clicked. The icon is also created.
	*/
	void createMenu(); /// We create the options of the menu, so as the icon.
};

#endif // OptionsScene_h
