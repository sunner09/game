#include "cocos2d.h"

USING_NS_CC;

class LayerLogin:public CCLayer
{
public:
	LayerLogin();
	~LayerLogin();

	CREATE_FUNC(LayerLogin);
	bool init();

public:
	void menuCallback(CCObject* pSender);
	
	 void onExit();
};