#ifndef EE_RENDERABLE
#define EE_RENDERABLE

#include "Script.h"
#include "Mesh.h"
#include "Texture.h"
#include <btBulletDynamicsCommon.h>

class Renderable {
public:
    virtual void Draw() {
        texture->Bind(0);
        mesh->Draw();
    };
    virtual void translate(float x, float y, float z) {
        body->translate(btVector3(x, y, z));
    }
    virtual void rotate(float x, float y, float z) {

    }
    virtual void scale(float x, float y, float z) {

    }
    virtual btRigidBody* getRigidBody() {
        return body;
    }
protected:
    btRigidBody* body;
    Script* script;
    Mesh* mesh;
    Texture* texture;
};

#endif
