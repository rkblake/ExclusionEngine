#ifndef EXCLUSIONENGINE_H
#define EXCLUSIONENGINE_H

enum {RENDERING, INPUT, PHYSICS, SCRIPTING};
#define ENGINE_COUNT 4

#include "engine.h"
#include "game.h"
#include "RenderingEngine.h"
#include "InputManager.h"
#include "shader.h"
#include "PhysicsEngine.h"
#include "ScriptingEngine.h"
#include "CoreEngine.h"
#include "window.h"
//#include <octree/octree.h>

#endif
