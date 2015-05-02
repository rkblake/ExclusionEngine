#include <stdio.h>
#include <string>

#include "ExclusionEngine.h"
#undef main

#ifdef _WIN32
	#include <direct.h>
#else
	#include <unistd.h>
#endif

class TestGame : public Game
{

};

int main(int, char**)
{
	CoreEngine* core = CoreEngine::GetInstance();
	ScriptingEngine* scripter = core->GetScriptingEngine();
	Script config = scripter->LoadScript("scripts/config.lua");
	int width = (int)scripter->GetNumber(config, "width");
	int height = (int)scripter->GetNumber(config, "height");
	const char* title = scripter->GetString(config, "title");
	Window window(width, height, title);
	window.SwapBuffers();
	/*
	//TestGame game;
	ScriptingEngine scripter;
	//char* path = system("pwd");
	//printf("%s", path);
	Script config = scripter.LoadScript("../scripts/config.lua");
	int width = (int)scripter.GetNumber(config, "width");
	int height = (int)scripter.GetNumber(config, "height");
	Window window(width, height, "test");
	window.SwapBuffers();
	*/

	return 0;
}
