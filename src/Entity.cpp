#include "Entity.h"

#include "InputManager.h"
#include "utils/utils.h"

Entity::Entity(const char* name)
	: m_mouseSensitivity(0.1f), m_rotation(Vec2f(0.0, 0.0)),
	m_accel(1.5f), m_decel(0.2f), m_maxSpeed(8.0f), m_mouseLocked(false)
{
	this->script = new Script(name);
	this->texture = new Texture(script->GetString("texture"));
    this->mesh = new Mesh(script->GetString("mesh"));

	m_pPhysicsWorld = PhysicsEngine::GetInstance().getWorld();
	m_direction = Vec3f(0, 0, 0);
	m_pCharacterController = new DynamicCharacterController(m_pPhysicsWorld, Vec3f(0, 0, 0), 1, 1, 1, 1);
}

Entity::Entity(int) {

}

Vec3f Entity::GetViewVec() {

}

Vec3f Entity::GetPosition() {
	return m_pCharacterController->GetPosition();
}

void Entity::Render() {
	texture->Bind(0);
    mesh->Draw();
}

void Entity::Update() {
	if(m_mouseLocked) {
		if(CoreEngine::GetInstance().GetInputManager()->KeyReleased(SDLK_ESCAPE)) {
			m_mouseLocked = false;

			InputManager::ShowMouse(true);
			InputManager::KeepMouseInWindow(false);
		}
		else {
			int dmx = 100 - CoreEngine::GetInstance().GetInputManager()->GetMouseX();
			int dmy = 100 - CoreEngine::GetInstance().GetInputManager()->GetMouseY();
			InputManager::SetMousePos(100, 100);

			m_rotation.x += dmx * m_mouseSensitivity;
			m_rotation.y += dmy * m_mouseSensitivity;

			// Wrap x
			m_rotation.x = Wrap(m_rotation.x, 360.0f);

			// Range checks for y
			if(m_rotation.y > 90.0f)
				m_rotation.y = 90.0f;
			else if(m_rotation.y < -90.0f)
				m_rotation.y = -90.0f;
		}
	}
	else {
		if(CoreEngine::GetInstance().GetInputManager()->KeyReleased(SDLK_ESCAPE))
			m_mouseLocked = true;

			InputManager::ShowMouse(false);
			InputManager::KeepMouseInWindow(true);

			// Set position now so don't get a view direction jump
			InputManager::SetMousePos(100, 100);
	}

	Run();

	//TODO: calculate player transform
}

void Entity::Run() {
	float xRotRads = DegToRad(m_rotation.x);
	float yRotRads = DegToRad(m_rotation.y);

	m_direction = RotationToVector(xRotRads, yRotRads);

	//TODO: set camera rotation

	Vec2f xzPlaneForwardDirection(sinf(xRotRads), cosf(xRotRads));
	Vec2f xzPlaneSideDirection(xzPlaneForwardDirection.y, -xzPlaneForwardDirection.x);

	if(CoreEngine::GetInstance().GetInputManager()->GetCurrentKeyState(SDLK_w)) {
		m_pCharacterController->Walk(-xzPlaneForwardDirection * m_accel);
	}
	else if(CoreEngine::GetInstance().GetInputManager()->GetCurrentKeyState(SDLK_s)) {
		m_pCharacterController->Walk(xzPlaneForwardDirection * m_accel);
	}
	if(CoreEngine::GetInstance().GetInputManager()->GetCurrentKeyState(SDLK_a)) {
		m_pCharacterController->Walk(-xzPlaneSideDirection * m_accel);
	}
	else if(CoreEngine::GetInstance().GetInputManager()->GetCurrentKeyState(SDLK_d)) {
		m_pCharacterController->Walk(xzPlaneSideDirection * m_accel);
	}

	if(CoreEngine::GetInstance().GetInputManager()->GetCurrentKeyState(SDLK_SPACE)) {
		m_pCharacterController->Jump();
	}

	m_pCharacterController->Update();

	//TODO: update camera position
}
