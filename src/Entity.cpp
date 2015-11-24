#include "Entity.h"

Entity::Entity(const char* name) {
	this->script = new Script(name);
	this->texture = new Texture(script->GetString("texture"));
    this->mesh = new Mesh(script->GetString("mesh"));

	//m_physicsWorld = PhysicsEngine::GetInstance().getWorld();
	direction = Vec3f(0, 0, 0);
	//controller = new DynamicCharacterController(m_physicsWorld, Vec3f(0, 0, 0), 1, 1, 1);
}

Entity::Entity(int) {

}

void Entity::Render() {

}

void Entity::Update() {

}
