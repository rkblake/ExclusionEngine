#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "ExclusionEngine.h"

class PhysicsEngine
{
public:
	static inline PhysicsEngine& GetInstance()
	{
		static PhysicsEngine sPhysicsEngine;
		return sPhysicsEngine;
	}
private:
	PhysicsEngine() {}
	~PhysicsEngine() {}

	//static PhysicsEngine* sPhysicsEngine;
};

#endif
