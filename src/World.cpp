#include "World.h"

World::World(const char* path_to_script) {
	script = new Script(path_to_script);
	btTriangleIndexVertexArray* tiva;
	// mesh = new Mesh(script->GetString("mesh"), tiva);
	//mesh = new Mesh(script->GetString("mesh"));
	texture = new Texture(script->GetString("texture"));

	//btCollisionShape* collisionShape = new btBvhTriangleMeshShape(tiva, false);
	btCollisionShape* collisionShape = new btStaticPlaneShape(btVector3(0, 0, 0), 1);
	btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
	btScalar mass = 0;
	btVector3 inertia(0, 0, 0);
	collisionShape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo bodyCI(mass, motionState, collisionShape, inertia);
	body = new btRigidBody(bodyCI);
}

void World::Render() {
	texture->Bind(0);
    mesh->Draw();
}
