#ifndef EE_SCRIPT_H
#define EE_SCRIPT_H

extern "C" {
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

struct table_node {
	char* name;
	char* script;
	table_node* children;
};

class Script {
public:
    Script() {}
    Script(const char* path) {LoadScript(path);}
    ~Script() {CloseScript();}

	double GetNumber(const char* var_name);
	bool GetBoolean(const char* var_name);
	const char* GetString(const char* var_name);
	table_node getTable(const char* var_name);
private:
    void LoadScript(const char* path);
    void CloseScript();

    lua_State* L;
};
#endif
