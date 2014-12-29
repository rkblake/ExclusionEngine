#include "CoreEngine.h"

CoreEngine::CoreEngine() {
	physics = PhysicsEngine::GetInstance();
	renderer = RenderingEngine::GetInstance();
	scripter = ScriptingEngine::GetInstance();
}
