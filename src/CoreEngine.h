#ifndef EE_COREENGINE_H
#define EE_COREENGINE_H

#include <string>

//extern SDL_Window* mWindow;
//class Game;

class PhysicsEngine;
class RenderingEngine;
//class ScriptingEngine;
class InputManager;

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
	void CreateWindow(const char* name, int width, int height);
private:
	//void init();
	CoreEngine();
	~CoreEngine();

	//Entity* player;
	//Camera* camera;
protected:

	//PhysicsEngine* physics;
	//RenderingEngine* renderer;
	//ScriptingEngine* scripter;
	//InputManager* input;
};

#endif
