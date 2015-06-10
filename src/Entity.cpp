#include "Entity.h"

/*Entity::Entity(Script script) {
    uuid = uuid_counter++;
    this->script = script;

    mesh = Mesh(script.GetString("mesh"));
    shader = LoadShaders(script.GetString("vertex_shader"), script.GetString("fragment_shader"));

    MatrixID = glGetUniformLocation(shader, "MVP");
	ViewMatrixID = glGetUniformLocation(shader, "V");
	ModelMatrixID = glGetUniformLocation(shader, "M");
}*/

Entity::Entity(const char* name) {
	std::string path_to_script = "scripts/" + std::string(name) + ".lua";
	std::string path_to_mesh = "res/" + std::string(name) + ".obj";
	std::string path_to_texture = "res/" +std::string(name) + ".jpg";
    this->script = Script(path_to_script.c_str());
    this->mesh = Mesh(path_to_mesh.c_str());
	this->texture = Texture(path_to_texture.c_str());
	texture.Bind(0);
    //shader = LoadShaders(script.GetString("vertex_shader"), script.GetString("fragment_shader"));

    //MatrixID = glGetUniformLocation(shader, "MVP");
    //ViewMatrixID = glGetUniformLocation(shader, "V");
    //ModelMatrixID = glGetUniformLocation(shader, "M");
	
	btCollisionShape* collisionShape = new btSphereShape(1);
	btDefaultMotionState* motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 25, 0)));
	btScalar mass = 1;
	btVector3 inertia(0, 0, 0);
	collisionShape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo bodyCI(mass, motionState, collisionShape, inertia);
	body = new btRigidBody(bodyCI);
}

void Entity::Draw() {
    //glUseProgram(shader);


    mesh.Draw();
}
