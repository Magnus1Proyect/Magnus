#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

/**
@brief    The cocos2d Application, this is the man behind the curtain, Magnus..? =)

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class  AppDelegate : private cocos2d::Application {
public:
	AppDelegate();
	virtual ~AppDelegate();

	/**
	@brief    Implement Director and Scene init code here.
	@return true    Initialize success, program continues.
	@return false   Initialize failed, program terminates.
	*/
	virtual bool applicationDidFinishLaunching();

	/**
	@brief  The function be called when the application enter background
	@param  pointer of the application
	*/
	virtual void applicationDidEnterBackground();

	/**
	@brief  The function be called when the application enter foreground, when its active 
	@param  pointer of the application
	*/
	virtual void applicationWillEnterForeground();
};

#endif // _APP_DELEGATE_H_


