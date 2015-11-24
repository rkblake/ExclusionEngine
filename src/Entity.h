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
#include <glm/glm.hpp>

#include "utils/Vec3f.h"
//#include "DynamicCharacterController.h"
//#include "PhysicsEngine.h"
//class DynamicCharacterController;
//class PhysicsEngine;

class Entity
{
public:
	Entity() {}
	Entity(int);
	//Entity(Script script);
	Entity(const char* name);
	~Entity() {}

	void Update();
	void Render();
private:
	Vec3f direction;
	//DynamicCharacterController* controller;
	//btDiscreteDynamicsWorld* m_physicsWorld;
	glm::mat4 m_entityTransform;

	Script* script;

	Mesh* mesh;
	Texture* texture;
	GLuint shader;
};

#endif
