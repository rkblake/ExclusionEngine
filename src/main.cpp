#include <stdio.h>
#include <string>

//#include "ExclusionEngine.h"
#include "CoreEngine.h"
#include "Script.h"
#undef main

/*class TestGame : public Game
{

};*/

int main(int, char**)
{
	CoreEngine* core = &CoreEngine::GetInstance();
	//ScriptingEngine* scripter = core->GetScriptingEngine();
	//Script config = scripter->LoadScript("scripts/config.lua");
	Script config("scripts/config.lua");
	int width = (int)config.GetNumber("width");
	int height = (int)config.GetNumber("height");
	const char* title = config.GetString("title");
	//Window window(width, height, title);
	//window.SwapBuffers();
	core->CreateWindow(title, width, height);
	core->Start();

	return 0;
}
