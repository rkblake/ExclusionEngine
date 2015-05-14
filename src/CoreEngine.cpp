#include "CoreEngine.h"

CoreEngine::CoreEngine():
	renderer(RenderingEngine::GetInstance()),
	physics(PhysicsEngine::GetInstance()),
	//scripter(ScriptingEngine::GetInstance()),
	input(InputManager::GetInstance())
{

}

CoreEngine::~CoreEngine()
{

}
