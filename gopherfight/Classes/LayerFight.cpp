#include "LayerFight.h"
#include "Defines.h"

LayerFight::LayerFight()
{
}

LayerFight::~LayerFight()
{

}

bool LayerFight::init()
{
	bool bRet=false;

	do
	{
		CC_BREAK_IF(!CCLayer::init());

		CCRenderTexture* rander=CCRenderTexture::create(500,500);
		rander->setAnchorPoint(ccp(0.5,0.5));
		rander->setPosition(CENTER);
		addChild(rander);

		rander->begin();
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				CCSprite* sprite=CCSprite::createWithSpriteFrameName("avatarbg.png");
				sprite->setAnchorPoint(CCPointZero);
				sprite->setPosition(ccp(100*i,100*j));
				sprite->visit();
			}
		}
		rander->end();


		bRet=true;
	}while(0);

	return bRet;
}

void LayerFight::update(float dt)
{

}

void LayerFight::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{

}
void LayerFight::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{

}
void LayerFight::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{

}

void LayerFight::onEnter()
{
	CCLayer::onEnter();
}

void LayerFight::onExit()
{

}

void LayerFight::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);
}

