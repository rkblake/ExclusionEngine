#ifndef EE_ENTITY_H
#define EE_ENTITY_H
/*
#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
*/
#include <btBulletDynamicsCommon.h>
#include <cstring>

#include <glm/glm.hpp>

#include "utils/Vec3f.h"
#include "utils/Vec2f.h"
#include "DynamicCharacterController.h"
//#include "PhysicsEngine.h"
//#include "Renderable.h"
#include "Script.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shaders.h"
#include "CoreEngine.h"
class DynamicCharacterController;
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
	void Run();
	Vec3f GetViewVec();
	Vec3f GetPosition();
private:
	Vec3f m_direction;
	Vec2f m_rotation;
	float m_accel, m_decel, m_maxSpeed, m_jumpVel, m_mouseSensitivity;
	bool m_mouseLocked;

	DynamicCharacterController* m_pCharacterController;
	btDiscreteDynamicsWorld* m_pPhysicsWorld;
	glm::mat4 m_entityTransform;

	Script* script;

	Mesh* mesh;
	Texture* texture;
	GLuint shader;
};

#endif
