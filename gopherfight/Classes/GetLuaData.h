
#ifndef __CppLua__HclcData__
#define __CppLua__HclcData__

#include "cocos2d.h"
using namespace cocos2d;

extern "C" 
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

class GetLuaData
{
public:
    static GetLuaData* sharedLuaData();
    
    static const char*  getString(const char* varName);
    static const char*  getStringOneOfTable(const char* varName,const char* keyName);
	static int				getValue(const char* varName);
    static int				getValueOneOfTable(const char* varName,const char* keyName);

    static const char* getStringsOfTable(const char* varName);
    static const char* callLuaFunction(const char* functionName);
    
    //------------  lua -> c++ ------------//
    static void callCppFunction(const char* fileName);
    
	
	static CCMenuItemSprite* getMenuItemByPlist(const char* key,const char* label="");

	static CCPoint getGlobalPosition(const char* key);
private:
    static int cppFunction(lua_State* ls);
    
    static GetLuaData* shared;
	static const char* luaFileName;

    static std::string getFileFullPath(const char* fileName);
    ~GetLuaData();
};

#endif /* defined(__CppLua__HclcData__) */