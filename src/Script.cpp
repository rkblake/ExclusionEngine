#include "Script.h"

double Script::GetNumber(const char* var_name) {
    lua_getglobal(L, var_name);
	if(!lua_isnumber(L, -1))
		printf("%s is not a number\n", var_name);
	double value = lua_tonumber(L, -1);
	lua_remove(L, -1);
	return value;
}

bool Script::GetBoolean(const char* var_name) {
    lua_getglobal(L, var_name);
	if(!lua_isboolean(L, -1))
		printf("%s is not a boolean\n", var_name);
	int value = lua_toboolean(L, -1);
	lua_remove(L, -1);
	return value == 1 ? true : false;
}

const char* Script::GetString(const char* var_name) {
    lua_getglobal(L, var_name);
	if(!lua_isstring(L, -1))
		printf("%s is not a string\n", var_name);
	const char* value = lua_tostring(L, -1);
	lua_remove(L, -1);
	return value;
}

void Script::LoadScript(const char* path) {
    lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	if(luaL_loadfile(L, path) || lua_pcall(L,0,0,0))
		printf("%s\n", lua_tostring(L, -1));
	this->L = L;
}

void Script::CloseScript() {
    lua_close(L);
}
