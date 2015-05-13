#ifndef EE_ENTITY_H
#define EE_ENTITY_H

#include "Script.h"
#include "Mesh.h"
#include "Shaders.h"

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif

static unsigned int uuid_counter = 0;

class Entity
{
public:
	Entity(Script script);
	Entity(const char* path_to_script);
	~Entity();

	void Draw();
	//inline InitUid() {uid = uid_counter++;}
private:
	float x, y, z;

	Script script;
	unsigned int uuid;


	Mesh mesh;
	GLuint shader;
};

#endif
