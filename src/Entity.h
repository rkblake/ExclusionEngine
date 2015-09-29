#ifndef EE_ENTITY_H
#define EE_ENTITY_H

#include "Renderable.h"
#include "Script.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shaders.h"

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#include <btBulletDynamicsCommon.h>
#include <cstring>

//static unsigned int uuid_counter = 0;

class Entity : public Renderable
{
public:
	Entity() {}
	Entity(int);
	//Entity(Script script);
	Entity(const char* name);
	~Entity() {}
	//btRigidBody* GetRigidBody() {return body;}
	void setVelocity(float x, float y, float z);
	//void translate(float x, float y, float z);
	//void Draw();
	//inline InitUid() {uid = uid_counter++;}
private:
	//float x, y, z;
	//btRigidBody* body;
	//GLuint ModelMatrixID, TextureID;


	//Script* script;
	//unsigned int uuid;


	//Mesh* mesh;
	//Texture* texture;
	//GLuint shader;
};

#endif
