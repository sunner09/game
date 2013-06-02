#pragma once

#include "cocos2d.h"
using namespace cocos2d;

#define SCREEN CCDirector::sharedDirector()->getWinSize()
#define VISIBLE CCDirector::sharedDirector()->getVisibleSize()
#define REALZERO CCDirector::sharedDirector()->getVisibleOrigin()
#define CENTER ccp(SCREEN.width/2,SCREEN.height/2)
#define TOP	ccp(REALZERO.x+VISIBLE.width/2,REALZERO.y+VISIBLE.height)
#define BOTTOM ccp(REALZERO.x+VISIBLE.width/2,REALZERO.y)
#define LEFT ccp(REALZERO.x,VISIBLE.height/2)
#define RIGHT ccp(REALZERO.x+VISIBLE.width,VISIBLE.height/2)
#define LEFTTOP ccp(REALZERO.x,REALZERO.y+VISIBLE.height)
#define RIGHTTOP ccp(REALZERO.x+VISIBLE.width,REALZERO.y+VISIBLE.height)
#define LEFTBOTTOM ccp(REALZERO.x,REALZERO.y)
#define RIGHTBOTTOM ccp(REALZERO.x+VISIBLE.width,REALZERO.y)

#define CURTIME GetCurTime()

#ifndef UINT64_C
#define UINT64_C(val) val##ui64
#endif
#define random_range(low,high) (rand()%(high-low+1))+low
#define frandom (float)rand() / UINT64_C(0x100000000)
#define frandom_range(low, high) ((high - low) * frandom) + low

#define CCARRAY_TFOREACH(__array__, __object__,__type__)                                                                         \
    if ((__array__) && (__array__)->data->num > 0)                                                                     \
    for(CCObject** __arr__ = (__array__)->data->arr, **__end__ = (__array__)->data->arr + (__array__)->data->num-1;    \
    __arr__ <= __end__ && (((__object__) = (__type__)*__arr__) != NULL/* || true*/);                                             \
    __arr__++)


inline float GetCurTime()
{
	timeval time;
	gettimeofday(&time,NULL);
	unsigned long millisecs = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (float)millisecs;
}