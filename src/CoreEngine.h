#ifndef EE_COREENGINE_H
#define EE_COREENGINE_H

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#include <SDL2/SDL.h>
#include <map>
#include <string>

#include "Entity.h"
#include "Window.h"
#include "RenderingEngine.h"
#include "PhysicsEngine.h"
#include "Script.h"
#include "World.h"
#include "InputManager.h"

class PhysicsEngine;
class RenderingEngine;
//class ScriptingEngine;
class InputManager;
class Entity;

class CoreEngine
{
public:

	static inline CoreEngine& GetInstance() {
		static CoreEngine sCoreEngine;
		return sCoreEngine;
	}
	//inline PhysicsEngine GetPhysicsEngine() {return physics;}
	//inline RenderingEngine* GetRenderingEngine() {return renderer;}
	//inline ScriptingEngine* GetScriptingEngine() {return scripter;}
	//inline InputManager* GetInputManager() {return input;}

	void Start();
	void Run();
	void Stop();
	Entity* GetNullEntity();
	void RegisterEntity(Entity* entity);
	Window* GetWindow() {return window;}
	InputManager* GetInputManager();
private:
	void CreateWindow(const char* name, int width, int height);
	CoreEngine();
	~CoreEngine();

	Entity* player;
	Window* window;
	InputManager* m_pInputManager;
	//const double FPS = 1.0/1.0;
protected:

	//PhysicsEngine* physics;
	//RenderingEngine* renderer;
	//ScriptingEngine* scripter;
	//InputManager* input;
};

#endif
