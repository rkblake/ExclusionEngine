#ifndef SCRIPTINGENGINE_H
#define SCRIPTINGENGINE_H

//#include "ExclusionEngine.h"
#include "ExclusionEngine.h"

extern "C" {
	#include <lua.h>
	#include <lauxlib.h>
	#include <lualib.h>
}

typedef lua_State* Script;

class ScriptingEngine : public CoreEngine {
public:
	//ScriptingEngine() {}
	//~ScriptingEngine() {}
	static inline ScriptingEngine* GetInstance() {return new ScriptingEngine;}
	Script LoadScript(const char* path);
	void CloseScript(Script L);
	double GetNumber(Script L, const char* var_name);
	bool GetBoolean(Script L, const char* var_name);
	const char* GetString(Script L, const char* var_name);
	//TODO: get fields for tables
private:
	ScriptingEngine() {}
	~ScriptingEngine() {}
};

#endif
