#include "SceneLogin.h"
#include "LayerLogin.h"

USING_NS_CC;


SceneLogin::SceneLogin(void)
{
}
SceneLogin::~SceneLogin(void)
{

}
bool SceneLogin::init()
{
	bool ret=false;

	do
	{
		CC_BREAK_IF(!CCScene::init());

		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui_skin.plist");

		LayerLogin* loginLayer=LayerLogin::create();
		addChild(loginLayer);

		ret=true;
	}while(0);

	return ret;
}