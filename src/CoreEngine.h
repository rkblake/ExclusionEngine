#ifndef COREENGINE_H
#define COREENGINE_H

#include <string>
#include "ExclusionEngine.h"
//class Game;

class PhysicsEngine;
class RenderingEngine;
class ScriptingEngine;

class CoreEngine {
public:
	CoreEngine();
	~CoreEngine();

	static inline PhysicsEngine* GetPhysicsEngine() {return physics;}
	static inline RenderingEngine* GetRenderingEngine() {return renderer;}
	static inline ScriptingEngine* GetScriptingEngine() {return scripter;}
private:
	
protected:
	static PhysicsEngine* physics;
	static RenderingEngine* renderer;
	static ScriptingEngine* scripter;
};

#endif
