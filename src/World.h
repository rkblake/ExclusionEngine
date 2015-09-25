#ifndef EE_WORLD
#define EE_WORLD

#include "Script.h"
#include "Mesh.h"
#include "Texture.h"
#include <btBulletDynamicsCommon.h>

class World {
public:
    World() {}
    World(const char* path_to_script);
private:
    Mesh* mesh;
    Script* script;
    btRigidBody* body;
};

#endif
