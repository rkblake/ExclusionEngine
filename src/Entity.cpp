#include "Entity.h"

Entity::Entity(const char* name) {
	this->script = new Script(name);
	this->texture = new Texture(script->GetString("texture"));
    this->mesh = new Mesh(script->GetString("mesh"));

	btCollisionShape* collisionShape = new btSphereShape(1);
	btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
	btScalar mass = 1;
	btVector3 inertia(0, 0, 0);
	collisionShape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo bodyCI(mass, motionState, collisionShape, inertia);
	body = new btRigidBody(bodyCI);
}

Entity::Entity(int) {
	btCollisionShape* collisionShape = new btSphereShape(1);
	btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
	btScalar mass = 1;
	btVector3 inertia(0, 0, 0);
	collisionShape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo bodyCI(mass, motionState, collisionShape, inertia);
	body = new btRigidBody(bodyCI);
}

void Entity::setVelocity(float x, float y, float z) {
	body->setLinearVelocity(btVector3(x, y, z));
}
/*
void Entity::translate(float x, float y, float z) {
	body->translate(btVector3(x, y, z));
}

void Entity::Draw() {
    //glUseProgram(shader);

	texture->Bind(0);
    mesh->Draw();
}
*/
