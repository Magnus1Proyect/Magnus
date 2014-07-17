#ifndef PauseScreen_h
#define PauseScreen_h

#include "cocos2d.h"

/**
@brief  This is the pause screen, when the user press esc this layer will appear
*/

class PauseScreen : public cocos2d::Layer {
public:

	/**
	@brief    We prepare our scene
	@return instance pointer We return the id (Identification)
	*/
	static cocos2d::Scene* createScene(); //We return the class instance pointer, its id

	/**
	@brief   PauseScreen is prepared and created/displayed if everything goes fine
	@return true    Initialize success, program continues.
	@return false   Initialize failed, program terminates.
	*/
	virtual bool init(); /// We call this when the player hit the "esc", what it does is return to the game

	/**
	@brief If the logo is clicked then we return to the Game 
	@param reference We require the reference of the game
	@param int level, if its a 0 then it refers to level 1, if its a 1 then it refers to level 2
	*/
	void returnToLevel(cocos2d::Ref* pSender, int level);

	/**
	@brief We create a function, basically we will do a layer above the background, this will allow us to use it.
	@param class type We need the class type to create the layer.
	*/
	CREATE_FUNC(PauseScreen);

private:
	/**
	@brief This method will resume the game
	*/
	void resumeLevel(); /// We resume the game
};

#endif // PauseScreen_h

