#include "LayerLogin.h"
#include "GetLuaData.h"
#include "SceneFight.h"

LayerLogin::LayerLogin()
{
}

LayerLogin::~LayerLogin()
{

}

bool LayerLogin::init()
{
	bool bRet=false;

	do
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSprite* bg=CCSprite::create(GetLuaData::getString("login_bg"));
		bg->setAnchorPoint(CCPointZero);
		addChild(bg);

		CCMenu* menu=CCMenu::create();
		menu->setPosition(CCPointZero);

		CCMenuItem* loginBtn=GetLuaData::getMenuItemByPlist("login_button");
		loginBtn->setTag(1);
		loginBtn->setTarget(this,menu_selector(LayerLogin::menuCallback));
		CCLabelTTF* btnLabel=CCLabelTTF::create(GetLuaData::getStringOneOfTable("login_button","label"),"",20);
		btnLabel->setAnchorPoint(ccp(0.5,0.5));
		btnLabel->setPosition(ccp(80,30));
		loginBtn->addChild(btnLabel);


		CCLabelTTF* loginTitle=CCLabelTTF::create(GetLuaData::getString("login_label"),"",40);
		loginTitle->setPosition(GetLuaData::getGlobalPosition("login_labpos"));
		loginTitle->setColor(ccBLUE);
		addChild(loginTitle);

		menu->addChild(loginBtn);

		addChild(menu);

		bRet=true;
	}while(0);

	return bRet;
}

void LayerLogin::menuCallback(CCObject* pSender)
{
	CCMenuItem* pItem=dynamic_cast<CCMenuItem*>(pSender);
	if(pItem)
	{
		if(pItem->getTag()==1)
		{
			CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(1.0,SceneFight::create()));
		}
	}
}

void LayerLogin::onExit()
{
	CCTextureCache::sharedTextureCache()->removeTextureForKey(GetLuaData::getString("login_bg"));
}


