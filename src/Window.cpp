#include "Window.h"
#include <stdio.h>



Window::Window(const char* title, int width, int height)
{
	windowWidth = width;
	windowHeight = height;

	SDL_Init(SDL_INIT_EVERYTHING);

	//required to get OpenGL 4.1. this may change
#ifdef __APPLE__
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#endif

	g_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
	_glContext = SDL_GL_CreateContext(g_window);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	//glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

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
}

Window::~Window()
{
	SDL_GL_DeleteContext(_glContext);
	SDL_DestroyWindow(g_window);
	SDL_Quit();
}

void Window::SwapBuffers()
{
	SDL_GL_SwapWindow(g_window);
}
