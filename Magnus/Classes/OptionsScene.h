#ifndef OptionsScene_h
#define OptionsScene_h

#include "cocos2d.h"

/**
@brief   

The reason for implement as private inheritance is to hide some interface call by Director.
*/

class OptionsScene : public cocos2d::Layer {
public:
	//We return the class instance pointer, its id
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	/// We call this when the player hit the "regresar al inicio", what it does is return to the front, the menu
	void returnGameMenu(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(OptionsScene);

private:
	/// We create the options of the menu, so as the icon.
	void createMenu();
};

#endif // OptionsScene_h
