#ifndef EE_MESH_H
#define EE_MESH_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <vector>
//#include <bullet/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.h>

#include "AssimpLoader.h"
#include "vboindexer.h"

class Mesh {
public:
    Mesh() {}
    Mesh(const char* path);
    //Mesh(const char* path, btTriangleMesh &mesh);
    ~Mesh();

    void Draw();
private:
    unsigned int indices_count;
    GLuint textureID;
    GLuint vao;
    GLuint vertex_buffer;
    GLuint uv_buffer;
    GLuint normal_buffer;
    GLuint element_buffer;
};

#endif
