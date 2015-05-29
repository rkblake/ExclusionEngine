#include "CoreEngine.h"

#include "RenderingEngine.h"
#include "Script.h"
#include "Entity.h"

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

void CoreEngine::Start() {
	Script config("scripts/config.lua");
	Script main("scripts/main.lua");
	int width = (int)config.GetNumber("width");
	int height = (int)config.GetNumber("height");
	const char* title = config.GetString("title");
	CreateWindow(title, width, height);
	//Entity test("scripts/test_entity.lua");

	Run();
}

Entity* CoreEngine::GetNullEntity() {

}

void CoreEngine::Run() {
	bool isRunning = true;
	SDL_Event e;

	while(isRunning) {
		/*double currentTime = SDL_GetTicks();
		nbFrames++;
		if ( currentTime - lastTime >= 1.0 ){ // If last prinf() was more than 1sec ago
			// printf and reset
			printf("%f ms/frame\n", double(nbFrames));
			nbFrames = 0;
			lastTime += 1.0;
		}*/

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		//update, render, and handle input here
		while(SDL_PollEvent(&e)) {
			switch(e.type) {
				case SDL_QUIT:
					isRunning = false;
					break;
				case SDL_MOUSEMOTION:
					//mouse motion
					//SDL_WarpMouse()
					break;
				case SDL_MOUSEBUTTONDOWN:
					//mouse button down
					break;
				case SDL_MOUSEBUTTONUP:
					//mouse button up
					break;
				case SDL_KEYDOWN:
					//key down
					break;
				case SDL_KEYUP:
					//key up
					break;
			}
		}

		window->SwapBuffers();
	}
}
