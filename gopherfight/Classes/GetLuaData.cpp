#include "GetLuaData.h"
#include "CCLuaEngine.h"
#include "Defines.h"

using namespace std;

GetLuaData* GetLuaData::shared=NULL;
const char* GetLuaData::luaFileName="layout.lua";

GetLuaData* GetLuaData::sharedLuaData()
{
    if(!shared)
	{
        shared = new GetLuaData();
    }
    return shared;
}

const char* GetLuaData::getString(const char* varName)
{
    lua_State*  ls = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    
	int isOpen = luaL_dofile(ls, getFileFullPath(luaFileName).c_str());
    if(isOpen!=0)
	{
        CCLOG("Open Lua Error: %i", isOpen);
        return NULL;
    }
    
    lua_settop(ls, 0);
    lua_getglobal(ls, varName);
    
	int statesCode = lua_isstring(ls, 1);
    if(statesCode!=1)
	{
        CCLOG("Open Lua Error: %i", statesCode);
        return NULL;
    }
    
	const char* str = lua_tostring(ls, 1);
    lua_pop(ls, 1);
    
    return str;
}
const char* GetLuaData::getStringOneOfTable(const char* varName,const char* keyName)
{
    
    lua_State*  ls = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    
	int isOpen = luaL_dofile(ls, getFileFullPath(luaFileName).c_str());
    if(isOpen!=0)
	{
        CCLOG("Open Lua Error: %i", isOpen);
        return NULL;
    }
    
    lua_getglobal(ls, varName);
    
    int statesCode = lua_istable(ls, -1);
    if(statesCode!=1)
	{
        CCLOG("Open Lua Error: %i", statesCode);
        return NULL;
    }
    
    lua_pushstring(ls, keyName);
    lua_gettable(ls, -2);
    const char* valueString = lua_tostring(ls, -1);
    
    lua_pop(ls, -1);
    
    return valueString;
}
const char* GetLuaData::getStringsOfTable(const char* varName)
{
    lua_State*  ls = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    
	int isOpen = luaL_dofile(ls, getFileFullPath(luaFileName).c_str());
    if(isOpen!=0){
        CCLOG("Open Lua Error: %i", isOpen);
        return NULL;
    }
    
    lua_getglobal(ls, varName);
    
    int it = lua_gettop(ls);
    lua_pushnil(ls);
    
    string result="";
    
    while(lua_next(ls, it))
    {
        string key = lua_tostring(ls, -2);
        string value = lua_tostring(ls, -1);
        
        result=result+key+":"+value+"\t";
        
        lua_pop(ls, 1);
    }
    lua_pop(ls, 1);
    
    return result.c_str();
}
int			   GetLuaData::getValue(const char* varName)
{
    lua_State*  ls = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    
	int isOpen = luaL_dofile(ls, getFileFullPath(luaFileName).c_str());
    if(isOpen!=0)
	{
        CCLOG("Open Lua Error: %i", isOpen);
        return NULL;
    }
    
    lua_settop(ls, 0);
    lua_getglobal(ls, varName);
    
	int statesCode = lua_isstring(ls, 1);
    if(statesCode!=1)
	{
        CCLOG("Open Lua Error: %i", statesCode);
        return NULL;
    }
    int result=0;
	result = lua_tointeger(ls, 1);
    lua_pop(ls, 1);
    
    return result;
}
int			   GetLuaData::getValueOneOfTable(const char* varName,const char* keyName)
{
    
    lua_State*  ls = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    
	int isOpen = luaL_dofile(ls, getFileFullPath(luaFileName).c_str());
    if(isOpen!=0)
	{
        CCLOG("Open Lua Error: %i", isOpen);
        return NULL;
    }
    
    lua_getglobal(ls, varName);
    
    int statesCode = lua_istable(ls, -1);
    if(statesCode!=1)
	{
        CCLOG("Open Lua Error: %i", statesCode);
        return NULL;
    }
    
    lua_pushstring(ls, keyName);
    lua_gettable(ls, -2);
	 int result=0;

    result = lua_tointeger(ls, -1);
    
    lua_pop(ls, -1);
    
    return result;
}
const char* GetLuaData::callLuaFunction(const char* functionName)
{
    lua_State*  ls = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    
	int isOpen = luaL_dofile(ls, getFileFullPath(luaFileName).c_str());
    if(isOpen!=0){
        CCLOG("Open Lua Error: %i", isOpen);
        return NULL;
    }
    
    lua_getglobal(ls, functionName);
    
    lua_pushstring(ls, "Himi");
    lua_pushnumber(ls, 23);
    lua_pushboolean(ls, true);
    
    /*
     lua_call
     num of param
     num of return
     */
    lua_call(ls, 3, 1);
    
    const char* iResult = lua_tostring(ls, -1);
    
    return iResult;
}

void  GetLuaData::callCppFunction(const char* fileName)
{
    
    lua_State*  ls = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    
    /*
     function must be static
     */
    lua_register(ls, "cppFunction", cppFunction);
    
	int isOpen = luaL_dofile(ls, getFileFullPath(fileName).c_str());
    if(isOpen!=0)
	{
        CCLOG("Open Lua Error: %i", isOpen);
        return;
    }
}

int GetLuaData::cppFunction(lua_State* ls)
{
    int luaNum = (int)lua_tonumber(ls, 1);
    int luaStr = (int)lua_tostring(ls, 2);
    
    /*
     return to lua
     */
    lua_pushnumber(ls, 321);
    lua_pushstring(ls, "Himi");
    
    /*
     return num
     */
    return 2;
}

std::string GetLuaData::getFileFullPath(const char* fileName)
{
    return CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);
}

GetLuaData::~GetLuaData()
{
    
    CC_SAFE_DELETE(shared);
    shared=NULL;
}


CCMenuItemSprite* GetLuaData::getMenuItemByPlist(const char* key,const char* label)
{
	if(key)
	{
		CCMenuItemSprite* pItem=CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName(getStringOneOfTable(key,"normal")),
			CCSprite::createWithSpriteFrameName(getStringOneOfTable(key,"selected")));

		if(pItem)
		{
			pItem->setPosition(getGlobalPosition(key));

			return pItem;
		}
	}
	return NULL;
}

CCPoint GetLuaData::getGlobalPosition(const char* key)
{
	std::string align=getStringOneOfTable(key,"align");
	int ox=getValueOneOfTable(key,"ox");
	int oy=getValueOneOfTable(key,"oy");
	CCPoint point=CCPointZero;
	if(align=="center")
	{
		point=ccpAdd(CENTER,ccp(ox,oy));
	}
	else if(align=="left")
	{
		point=ccpAdd(LEFT,ccp(ox,oy));
	}
	else if(align=="right")
	{
		point=ccpAdd(RIGHT,ccp(ox,oy));
	}
	else if(align=="top")
	{
		point=ccpAdd(TOP,ccp(ox,oy));
	}
	else if(align=="bottom")
	{
		point=ccpAdd(BOTTOM,ccp(ox,oy));
	}
	else if(align=="lefttop")
	{
		point=ccpAdd(LEFTTOP,ccp(ox,oy));
	}
	else if(align=="leftbottom")
	{
		point=ccpAdd(LEFTBOTTOM,ccp(ox,oy));
	}
	else if(align=="righttop")
	{
		point=ccpAdd(RIGHTTOP,ccp(ox,oy));
	}
	else if(align=="rightbottom")
	{
		point=ccpAdd(RIGHTBOTTOM,ccp(ox,oy));
	}
	return point;
}