#ifndef EE_COREENGINE_H
#define EE_COREENGINE_H

#include <string>
#include "ExclusionEngine.h"
//class Game;

class PhysicsEngine;
class RenderingEngine;
//class ScriptingEngine;
class InputManager;

class CoreEngine
{
public:

	static inline CoreEngine* GetInstance() {
		static CoreEngine sCoreEngine;
		CoreEngine* core_ptr = &sCoreEngine;
		return core_ptr;
	}
	inline PhysicsEngine* GetPhysicsEngine() {return physics;}
	inline RenderingEngine* GetRenderingEngine() {return renderer;}
	//inline ScriptingEngine* GetScriptingEngine() {return scripter;}
	inline InputManager* GetInputManager() {return input;}
private:

	CoreEngine();
	~CoreEngine();
protected:

	PhysicsEngine* physics;
	RenderingEngine* renderer;
	//ScriptingEngine* scripter;
	InputManager* input;
};

#endif
