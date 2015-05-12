#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices) {
    drawCount = numVertices;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(NUM_BUFFERS, vab);
    glBindBuffer(GL_ARRAY_BUFFER, vab[POSITION_VB]);
    //glBufferData();

    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vao);
}
