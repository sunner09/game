#include "cocos2d.h"

USING_NS_CC;

class LayerFight:public CCLayer
{
public:
	LayerFight();
	~LayerFight();

	CREATE_FUNC(LayerFight);
	bool init();

	void update(float dt);

	void onEnter();
	void onExit();
	void registerWithTouchDispatcher();

	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

public:

};