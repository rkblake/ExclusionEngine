#ifndef EE_ENTITY_H
#define EE_ENTITY_H

#include "ScriptingEngine.h"
#include "Mesh.h"

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif


class Entity
{
public:
	Entity(Script script);
	~Entity();


	//inline InitUid() {uid = uid_counter++;}
private:
	Script script;
	unsigned int uuid;
	static unsigned int uuid_counter = 0;

	Mesh mesh;
};

#endif
