#ifndef EE_PHYSICSENGINE_H
#define EE_PHYSICSENGINE_H

#include "Entity.h"

#include <btBulletDynamicsCommon.h>
#include <bullet/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h>
#include <map>

class PhysicsEngine
{
public:
	static inline PhysicsEngine& GetInstance()
	{
		static PhysicsEngine sPhysicsEngine;
		return sPhysicsEngine;
	}
	void Register(Entity* e, unsigned int uid);
	void Unregister(Entity* e, unsigned int uid);
	void StepSimulation();
	void Dispose();

private:
	PhysicsEngine();
	~PhysicsEngine();

	std::map<unsigned int, btRigidBody> bodies;

	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;
};

#endif
