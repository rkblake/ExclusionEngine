#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine() {
    broadphase = new btDbvtBroadphase();
    //broadphase->getOverlappingPairCache()->setInternalGhostPairCallback(new btGhostPairCallback());
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    btGImpactCollisionAlgorithm::registerAlgorithm(dispatcher);
    //register of algorithms here
    solver = new btSequentialImpulseConstraintSolver;
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0, -1, 0));

	btCollisionShape* ground = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
	btDefaultMotionState* groundState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, groundState, ground, btVector3(0, 0, 0));
	btRigidBody* groundBody = new btRigidBody(groundRigidBodyCI);
	dynamicsWorld->addRigidBody(groundBody);
}

PhysicsEngine::~PhysicsEngine() {
    delete dynamicsWorld;
    delete solver;
    delete dispatcher;
    delete collisionConfiguration;
    delete broadphase;
}

void PhysicsEngine::RegisterEntity(Entity* entity) {
	dynamicsWorld->addRigidBody(entity->getRigidBody());
    //if(entity->getGhostObject() != nullptr)
        //dynamicsWorld->addCollisionObject(entity->getGhostObject());
    //if(entity->getController() != nullptr)
        //dynamicsWorld->addAction(entity->getController());
}

void PhysicsEngine::Unregister(Entity* entity) {
    dynamicsWorld->removeRigidBody(entity->getRigidBody());
}

void PhysicsEngine::SetWorld(World* w) {
	if(world != nullptr)
		dynamicsWorld->removeRigidBody(world->getRigidBody());
	world = w;
	dynamicsWorld->addRigidBody(world->getRigidBody());
    world->getRigidBody()->setGravity(btVector3(0, 0, 0));
}

void PhysicsEngine::StepSimulation() {
    dynamicsWorld->stepSimulation(1, 1.0/60);
}

void Dispose () {

}
