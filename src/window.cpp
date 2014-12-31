#include "window.h"
#include <stdio.h>

Window::Window(int width,int height,char* title)
{
	m_width = width;
	m_height = height;

	SDL_Init(SDL_INIT_EVERYTHING);

	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	glewExperimental = true;
	GLenum err = glewInit();
	if(glewInit() != err) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(1);
	}

	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_Delay(2000);
}

Window::~Window()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Window::SwapBuffers()
{
	SDL_GL_SwapWindow(m_window);
}

void Window::Update()
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
}
