#include "AppDelegate.h"
#include "MenuInicio.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() {
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView(); // we open the window
	if (!glview) { // if there is no window then we create it.
		glview = GLView::create("Magnus");
		director->setOpenGLView(glview);
	}

	// Los graficos estan disennados para 1024x768
	glview->setDesignResolutionSize(1024, 768, ResolutionPolicy::EXACT_FIT);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	// En PC se puede cambiar el tamanno de la ventana, en dispositivos moviles el tamanno es fijo
	glview->setFrameSize(1024, 768);
#endif

#if (COCOS2D_DEBUG == 1)
	// turn on display FPS only in debug mode
	director->setDisplayStats(true);
#endif

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object
	auto scene = MenuInicio::createScene();

	// run the programn, we tell him the scene
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too, basically when use alt-tab and/or the game is
//in someway pushed to the background, well, we stop the music and the animations.
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

	// we are using SimpleAudioEngine, so it must be paused, here we do it.
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again, we resume the game.
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

