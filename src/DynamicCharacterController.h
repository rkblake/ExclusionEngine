#ifndef EE_DYNAMICCHARACTERCONTROLLER
#define EE_DYNAMICCHARACTERCONTROLLER

#include <glm/glm.hpp>
#include <vector>
#include <cmath>

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include <BulletCollision/CollisionDispatch/btGhostObject.h>

#include "PhysicsEngine.h"
#include "utils/utils.h"

class DynamicCharacterController
{
private:
	// Physics
	btDiscreteDynamicsWorld* m_pPhysicsWorld;
	//Scene* m_pScene;

	btCollisionShape* m_pCollisionShape;
	btDefaultMotionState* m_pMotionState;
	btRigidBody* m_pRigidBody;
	btPairCachingGhostObject* m_pGhostObject;

	bool m_onGround;
	//bool m_onJumpableGround; // A bit lower contact than just onGround
	bool m_hittingWall;

	float m_bottomYOffset;
	float m_bottomRoundedRegionYOffset;

	float m_stepHeight;

	btTransform m_motionTransform;

	Vec3f m_manualVelocity;
	std::vector<Vec3f> m_surfaceHitNormals;

	btVector3 m_previousPosition;

	float m_jumpRechargeTimer;

	void ParseGhostContacts();

	void UpdatePosition();
	void UpdateVelocity();

public:
	float m_deceleration;
	float m_maxSpeed;
	float m_jumpImpulse;

	float m_jumpRechargeTime;

	//DynamicCharacterController(Scene* pScene, SceneObject_PhysicsWorld* pPhysicsWorld, const Vec3f spawnPos, float radius, float height, float mass, float stepHeight);
    DynamicCharacterController(btDiscreteDynamicsWorld* pPhysicsWorld, const Vec3f spawnPos, float radius, float height, float mass, float stepHeight);
	~DynamicCharacterController();

	// Acceleration vector in XZ plane
	void Walk(const Vec2f dir);

	// Ignores y
	void Walk(const Vec3f dir);

	void Update();

	void Jump();

	Vec3f GetPosition() const;
	Vec3f GetVelocity() const;

	bool IsOnGround() const;
};

#endif
