#include "PhysicsEngine.h"


PhysicsEngine::PhysicsEngine() {
    broadphase = new btDbvtBroadphase();
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    btGImpactCollisionAlgorithm::registerAlgorithm(dispatcher);
    //register of algorithms here
    solver = new btSequentialImpulseConstraintSolver;
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0, -10, 0));

}

PhysicsEngine::~PhysicsEngine() {
    delete dynamicsWorld;
    delete solver;
    delete dispatcher;
    delete collisionConfiguration;
    delete broadphase;
}

void PhysicsEngine::Register(Entity* e, unsigned int uid) {
    
}

void PhysicsEngine::Unregister(Entity* e, unsigned int uid) {

}

void PhysicsEngine::StepSimulation() {
    dynamicsWorld->stepSimulation(1, 1.0/60);
}

void Dispose () {

}
