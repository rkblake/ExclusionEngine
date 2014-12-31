#include "ScriptingEngine.h"

Script ScriptingEngine::LoadScript(const char* path)
{
    Script L = luaL_newstate();
    luaL_openlibs(L);
    if(luaL_loadfile(L, path) || lua_pcall(L,0,0,0))
        printf("%s\n", lua_tostring(L, -1));
    return L;
}

void ScriptingEngine::CloseScript(Script L)
{
    lua_close(L);
}

double ScriptingEngine::GetNumber(Script L, const char* var_name)
{
    lua_getglobal(L, var_name);
    if(!lua_isnumber(L, -1))
        printf("%s is not a number\n", var_name);
    double value = lua_tonumber(L, -1);
    lua_remove(L, -1);
    return value;
}

bool ScriptingEngine::GetBoolean(Script L, const char* var_name)
{
    lua_getglobal(L, var_name);
    if(!lua_isboolean(L, -1))
        printf("%s is not a boolean\n", var_name);
    int value = lua_toboolean(L, -1);
    lua_remove(L, -1);
    return value == 1 ? true : false;
}

const char* ScriptingEngine::GetString(Script L, const char* var_name)
{
    lua_getglobal(L, var_name);
    if(!lua_isstring(L, -1))
        printf("%s is not a string\n", var_name);
    const char* value = lua_tostring(L, -1);
    lua_remove(L, -1);
    return value;
}
