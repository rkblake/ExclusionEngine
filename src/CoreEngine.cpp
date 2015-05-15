#include "CoreEngine.h"

//#include "ExclusionEngine.h"
#include "RenderingEngine.h"

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

void CoreEngine::init() {

}

CoreEngine::~CoreEngine()
{

}

void CoreEngine::CreateWindow(const char* title, int width, int height) {
	RenderingEngine::GetInstance().CreateWindow(title, width, height);
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

		/*glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glFrustum(-aspect*near/lens, aspect*near/lens, -near/lens, near/lens, near, far);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/

		//update, render, and handle input here

		//SDL_GL_SwapWindow(m_window);
	}
}
