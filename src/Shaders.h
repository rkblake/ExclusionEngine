#ifndef EE_SHADERS_H
#define EE_SHADERS_H

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

#endif
