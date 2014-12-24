#include <stdio.h>
#include <string>

#include "ExclusionEngine.h"
#undef main

class TestGame : public Game {

};

int main(int, char**)
{
	//TestGame game;
	ScriptingEngine scripter;
	Script config = scripter.LoadScript("../scripts/config.lua");
	int *width = (int*)scripter.GetNumber(config, "width");
	int *height = (int*)scripter.GetNumber(config, "height");
	Window window(*width, *height, "test");
	window.SwapBuffers();
	//RenderingEngine renderer(window);
	//CoreEngine
	
	return 0;
}
