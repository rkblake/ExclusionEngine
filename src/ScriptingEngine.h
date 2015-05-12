#ifndef EE_SCRIPTINGENGINE_H
#define EE_SCRIPTINGENGINE_H

class CoreEngine;
#include "CoreEngine.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

typedef lua_State* Script;

class ScriptingEngine : public Engine
{

public:
	static inline ScriptingEngine* GetInstance()
	{
		static ScriptingEngine sScriptingEngine;
		ScriptingEngine* scripter = &sScriptingEngine;
		return scripter;
	}
	Script LoadScript(const char* path);
	void CloseScript(Script L);
	double GetNumber(Script L, const char* var_name);
	bool GetBoolean(Script L, const char* var_name);
	const char* GetString(Script L, const char* var_name);
	//TODO: get fields for tables
private:
	CoreEngine* core;
	ScriptingEngine() {}
	~ScriptingEngine() {}
};

#endif
