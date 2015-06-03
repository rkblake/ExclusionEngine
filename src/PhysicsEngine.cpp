#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine() {
    broadphase = new btDbvtBroadphase();
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    btGImpactCollisionAlgorithm::registerAlgorithm(dispatcher);
    //register of algorithms here
    solver = new btSequentialImpulseConstraintSolver;
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0, -9.8, 0));

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
	//btScalar mass = 1;
	//btVector3 fallInertia(0, 0, 0);
	//entity->GetRigidBody()->getCollisionShape()->calculateLocalInertia(mass, fallInertia);
	//btRigidBody::btRigidBodyConstructionInfo entityCI(1, entity->GetRigidBody()->getMotionState(), entity->GetRigidBody()->getCollisionShape(), fallInertia);
	//btRigidBody* body = new btRigidBody(entityCI);
	dynamicsWorld->addRigidBody(entity->GetRigidBody());
}

void PhysicsEngine::Unregister(Entity* entity) {

}

void PhysicsEngine::StepSimulation() {
    dynamicsWorld->stepSimulation(1, 1.0/60);
}

void Dispose () {

}
