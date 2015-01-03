#ifndef COREENGINE_H
#define COREENGINE_H

#include <string>
#include "ExclusionEngine.h"
//#include "PhysicsEngine.h"
//#include "RenderingEngine.h"
//#include "ScriptingEngine.h"
//class Game;

class PhysicsEngine;
class RenderingEngine;
class ScriptingEngine;
class InputManager;

class CoreEngine
{
public:

	static inline CoreEngine& GetInstance()
	{
		static CoreEngine sCoreEngine;
		return sCoreEngine;
	}
	inline PhysicsEngine* GetPhysicsEngine()
	{
		PhysicsEngine* physics_ptr = &physics;
		return physics_ptr;
	}
	inline RenderingEngine* GetRenderingEngine()
	{
		RenderingEngine* renderer_ptr = &renderer;
		return renderer_ptr;
	}
	inline ScriptingEngine* GetScriptingEngine()
	{
		ScriptingEngine* scripter_ptr = &scripter;
		return scripter_ptr;
	}
	inline InputManager* GetInputManager()
	{
		InputManager* input_ptr = &input;
		return input_ptr;
	}
private:

protected:
	CoreEngine();
	~CoreEngine();

	PhysicsEngine& physics;
	RenderingEngine& renderer;
	ScriptingEngine& scripter;
	InputManager& input;
};

#endif
