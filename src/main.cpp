#include <stdio.h>
#include <string>

//#include "ExclusionEngine.h"
#include "CoreEngine.h"
#include "Script.h"
#undef main

int main(int, char**)
{
	CoreEngine::GetInstance().Start("scripts/config.lua");
	return 0;
}
