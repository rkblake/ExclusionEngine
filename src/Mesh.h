#ifndef EE_MESH_H
#define EE_MESH_H

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <glm/glm.hpp>

class Vertex {
public:
    Vertex(const glm::vec3& pos) {this->pos = pos;}
private:
    glm::vec3 pos;
};

class Mesh {
public:
    Mesh() {}
    Mesh(Vertex* vertices, unsigned int numVertices);
    ~Mesh();

    void Draw();
private:
    enum {
        POSITION_VB,
        NUM_BUFFERS
    };

    GLuint vao;
    GLuint vab[NUM_BUFFERS];
    unsigned int drawCount;
};

#endif
