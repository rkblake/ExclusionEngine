#ifndef EE_PHYSICSENGINE_H
#define EE_PHYSICSENGINE_H

#include "ExclusionEngine.h"

class PhysicsEngine
{
public:
	static inline PhysicsEngine* GetInstance()
	{
		static PhysicsEngine sPhysicsEngine;
		PhysicsEngine* physics = &sPhysicsEngine;
		return physics;
	}
private:
	PhysicsEngine() {}
	~PhysicsEngine() {}

	//static PhysicsEngine* sPhysicsEngine;
};

#endif
