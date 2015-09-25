#include "CoreEngine.h"

#include "RenderingEngine.h"
#include "PhysicsEngine.h"
#include "Script.h"

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#include <SDL2/SDL.h>
#include <map>

CoreEngine::CoreEngine()
	//renderer(RenderingEngine::GetInstance()),
	//physics(PhysicsEngine::GetInstance()),
	//scripter(ScriptingEngine::GetInstance()),
	//input(InputManager::GetInstance())
{

}

CoreEngine::~CoreEngine()
{

}

void CoreEngine::CreateWindow(const char* title, int width, int height) {
	window = RenderingEngine::GetInstance().CreateWindow(title, width, height);
}

void CoreEngine::RegisterEntity(Entity* entity) {
	RenderingEngine::GetInstance().RegisterEntity(entity);
	PhysicsEngine::GetInstance().RegisterEntity(entity);
}

void CoreEngine::Start() {
	Script config("scripts/config.lua");
	//Script main("scripts/main.lua");
	int width = (int)config.GetNumber("width");
	int height = (int)config.GetNumber("height");
	const char* title = config.GetString("title");
	CreateWindow(title, width, height);
	RenderingEngine::GetInstance().Init();
	Entity* test = new Entity("scripts/test_entity.lua");
	Entity* cube = new Entity("scripts/cube.lua");
	test->translate(0, 50, 0);
	cube->translate(10,25,0);
	RegisterEntity(cube);
	RegisterEntity(test);
	Entity* null = GetNullEntity();
	RenderingEngine::GetInstance().AttachEntity(cube);
	Run();
}

void CoreEngine::Stop() {
	//do cleanup
}

Entity* CoreEngine::GetNullEntity() {
	return new Entity(0);
}

void CoreEngine::Run() {
	bool isRunning = true;
	SDL_Event e;
	const Uint8* keys;
	keys = SDL_GetKeyboardState(NULL);
	double lastTime = SDL_GetTicks();
	double deltaTime, currentTime;

	while(isRunning) {
		currentTime = SDL_GetTicks();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		PhysicsEngine::GetInstance().StepSimulation();
		RenderingEngine::GetInstance().RenderScene();
		window->SwapBuffers();

		while(SDL_PollEvent(&e)) {
			switch(e.type) {
				case SDL_QUIT:
					isRunning = false;
					break;
			}
		}

		if(keys[SDL_SCANCODE_ESCAPE])
			isRunning = false;

		if(FPS - deltaTime > 0)
			SDL_Delay(FPS - deltaTime);
	}
	Stop();
}
