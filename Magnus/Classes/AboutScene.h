#ifndef AboutScene_h
#define AboutScene_h

#include "cocos2d.h"

/**
@brief  Window where we will explain the game and a bit of ourselves
*/

class AboutScene : public cocos2d::Layer {
public:
	//We return the class instance pointer, its id
	static cocos2d::Scene* createScene();

	/**
	@brief    The About Scene is prepared and created if everything goes fine
	@return true    Initialize success, program continues.
	@return false   Initialize failed, program terminates.
	*/
	virtual bool init();

	/// We call this when the player hit the "regresar al inicio", what it does is return to the front, the menu

	/**
	@brief If the logo is clicked then we return to the Game Menu
	@param We require the reference of the game menu
	*/
	void returnGameMenu(cocos2d::Ref* pSender);

	/**
	@brief We create a function, basically we will do a layer above the background, this will allow us to use it.
	@param We need the class type to create the layer.
	*/
	CREATE_FUNC(AboutScene);

private:
	/**
	@brief We create the Menu so we can go back to it when the logo/home button is clicked. The icon is also created.
	*/
	void createMenu(); /// We create the options of the menu, so as the icon.
};

#endif // AboutScene_h