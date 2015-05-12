#ifndef EXCLUSIONENGINE_H
#define EXCLUSIONENGINE_H

enum {RENDERING, INPUT, PHYSICS, SCRIPTING};
#define ENGINE_COUNT 4

#include "Engine.h"
#include "game.h"
#include "RenderingEngine.h"
#include "InputManager.h"
#include "Shaders.h"
#include "PhysicsEngine.h"
//#include "ScriptingEngine.h"
#include "Script.h"
#include "CoreEngine.h"
#include "Window.h"
//#include <octree/octree.h>

#endif
