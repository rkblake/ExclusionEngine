#ifndef EE_PHYSICSENGINE_H
#define EE_PHYSICSENGINE_H

#include "Entity.h"
#include "World.h"

#include <btBulletDynamicsCommon.h>
#include <bullet/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h>
#include <map>
#include <vector>

class PhysicsEngine
{
public:
	static inline PhysicsEngine& GetInstance()
	{
		static PhysicsEngine sPhysicsEngine;
		return sPhysicsEngine;
	}
	void SetWorld(World* w);
	void RegisterEntity(Entity* e);
	void Unregister(Entity* e);
	void StepSimulation();
	void Dispose();
    btDiscreteDynamicsWorld* getWorld() {return dynamicsWorld;}

private:
	PhysicsEngine();
	~PhysicsEngine();

	//std::map<unsigned int, PhysicsObjectWrapper> PhysicsObjects;
	std::vector<Entity*> entities;
	World* world;

	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;
};

#endif
