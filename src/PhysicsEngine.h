#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "ExclusionEngine.h"

class PhysicsEngine : public CoreEngine {
public:
	static inline PhysicsEngine* GetInstance() {return new PhysicsEngine;}
private:
	PhysicsEngine() {}
	~PhysicsEngine() {}
};

#endif
