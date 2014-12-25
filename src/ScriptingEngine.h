#ifndef SCRIPTINGENGINE_H
#define SCRIPTINGENGINE_H

extern "C" {
	#include <lua.h>
	#include <lauxlib.h>
	#include <lualib.h>
}

typedef lua_State* Script;

class ScriptingEngine {
public:
	ScriptingEngine() {}
	~ScriptingEngine() {}

	Script LoadScript(const char* path);
	void CloseScript(Script L);
	double GetNumber(Script L, const char* var_name);
	bool GetBoolean(Script L, const char* var_name);
	const char* GetString(Script L, const char* var_name);
	//TODO: get fields for tables
private:

};

#endif
