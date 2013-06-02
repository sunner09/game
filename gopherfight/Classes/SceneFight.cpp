#include "SceneFight.h"
#include "LayerFight.h"

USING_NS_CC;


SceneFight::SceneFight(void)
{
}
SceneFight::~SceneFight(void)
{

}
bool SceneFight::init()
{
	bool ret=false;

	do
	{
		CC_BREAK_IF(!CCScene::init());

		LayerFight* fightLayer=LayerFight::create();
		addChild(fightLayer);

		ret=true;
	}while(0);

	return ret;
}