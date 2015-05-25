#ifndef EE_PHYSICSENGINE_H
#define EE_PHYSICSENGINE_H

#include "Entity.h"

#include <btBulletDynamicsCommon.h>
#include <bullet/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h>
#include <map>

class ExclusionMotionState : public btMotionState {
public:
    void getWorldTransform (btTransform &worldTrans) const {

    }
    void setWorldTransform (const btTransform &worldTrans) {

    }
};

typedef struct {
    ExclusionMotionState motionState;
    btRigidBody body;
} PhysicsObjectWrapper;

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

	std::map<unsigned int, PhysicsObjectWrapper> PhysicsObjects;

	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;
};

#endif
