#ifndef EE_WINDOW_H
#define EE_WINDOW_H

//#include "InputManager.h"
#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#include <SDL2/SDL.h>
//#include <SDL2/SDL_opengl.h>

class Window
{
public:
	Window() {}
	Window(const char*,int,int);
	~Window();

	void SwapBuffers();
	//void Update();
	void SetFullscreen();
	//void BindAsRenderTarget() const;
	inline int getWidth()
	{
		return _width;
	}
	inline int getHeight()
	{
		return _height;
	}
	inline SDL_Window* GetWindow()
	{
		return _window;
	}
	inline bool getIsCloseRequested()
	{
		return isCloseRequested;
	}
private:
	int _width, _height;
	bool isCloseRequested;
	SDL_Window* _window;
	SDL_GLContext _glContext;
	SDL_Event e;
	//InputManager* input;
};

#endif
