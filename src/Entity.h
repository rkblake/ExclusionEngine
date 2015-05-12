#ifndef EE_ENTITY_H
#define EE_ENTITY_H

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#include "ScriptingEngine.h"

class Entity
{
public:
	Entity() {}
	~Entity() {}


	//inline InitUid() {uid = uid_counter++;}
private:
	const char* name;
	Script L;
	//static int uid_counter = 0;
	int uid;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint programID;
	GLuint Texture;
	GLuint VertexArrayID;
	GLuint normalbuffer;
};

#endif
