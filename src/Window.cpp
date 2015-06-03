#include "Window.h"
#include <stdio.h>

Window::Window(const char* title, int width, int height)
{
	_width = width;
	_height = height;

	SDL_Init(SDL_INIT_EVERYTHING);

	//required to get OpenGL 4.1. this may change
#ifdef __APPLE__
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#endif

	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL);
	_glContext = SDL_GL_CreateContext(_window);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	//printf("%s\n", glGetString(GL_VERSION));

#ifndef __APPLE__
	glewExperimental = true;
	GLenum err = glewInit();
	if(glewInit() != err) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(1);
	}
	else		
		printf("%s\n", glGetString(GL_VERSION));
#else	
	printf("%s\n", glGetString(GL_VERSION));
#endif

	//glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(0,0,1,1);
	//SwapBuffers();
	//glClear(GL_COLOR_BUFFER_BIT);
	SDL_Delay(2000);
}

Window::~Window()
{
	SDL_GL_DeleteContext(_glContext);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Window::SwapBuffers()
{
	SDL_GL_SwapWindow(_window);
}

/*void Window::Update()
{
	while(SDL_PollEvent(&e)) {
		switch(e.type) {
		case SDL_QUIT:
			isCloseRequested = true;
			break;
		case SDL_KEYDOWN:
			//key down
			break;
		case SDL_KEYUP:
			//key up
			break;
		case SDL_MOUSEBUTTONDOWN:
			//mouse down
			break;
		case SDL_MOUSEBUTTONUP:
			//mouse up
			break;
		}

	}
}*/
