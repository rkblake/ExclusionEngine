#ifndef EE_WORLD
#define EE_WORLD

#include "Renderable.h"
#include "Script.h"
#include "Mesh.h"
#include "Texture.h"
#include <btBulletDynamicsCommon.h>
#include <bullet/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.h>

class World : public Renderable {
public:
    World() {}
    World(const char* path_to_script);

	//btRigidBody* GetRigidBody() {return body;}
	//void Draw();
private:
    //Mesh* mesh;
    //Script* script;
	//Texture* texture;
    //btRigidBody* body;
};

#endif
