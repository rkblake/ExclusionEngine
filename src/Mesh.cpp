#include "Mesh.h"

Mesh::Mesh(const char* path, btTriangleIndexVertexArray* tiva) {
    //TextureID  = glGetUniformLocation(programID, "texture_sampler");

    std::vector< glm::vec3 > vertices;
	std::vector< glm::vec2 > uvs;
	std::vector< glm::vec3 > normals;
	AssimpLoadFile(path, vertices, uvs, normals);

	std::vector<unsigned short> indices;
	std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;
	indexVBO(vertices, uvs, normals, indices, indexed_vertices, indexed_uvs, indexed_normals);
    //AssimpLoadFile(path, indexed_vertices, indexed_uvs, indexed_normals, indices);

    indices_count = indices.size();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, indexed_vertices.size() * sizeof(glm::vec3), &indexed_vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );

	glGenBuffers(1, &uv_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
	glBufferData(GL_ARRAY_BUFFER, indexed_uvs.size() * sizeof(glm::vec2), &indexed_uvs[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );

	glGenBuffers(1, &normal_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, normal_buffer);
	glBufferData(GL_ARRAY_BUFFER, indexed_normals.size() * sizeof(glm::vec3), &indexed_normals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );

	glGenBuffers(1, &element_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0] , GL_STATIC_DRAW);

    glBindVertexArray(0);

    if(tiva != 0) {
        tiva = new btTriangleIndexVertexArray(
            indices.size() / 3, //assuming indices is divisible by 3 may not be true
            (int*)&indices[0],
            sizeof(unsigned short),
            indexed_vertices.size(),
            (btScalar*)&indexed_vertices[0],
            sizeof(glm::vec3)
        );
    }
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vao);
}

void Mesh::Draw() {
    glBindVertexArray(vao);

    glDrawElements(GL_TRIANGLES, indices_count, GL_UNSIGNED_SHORT, (void*)0 );
	//glDrawArrays(GL_TRIANGLES, 0, indices_count);

    glBindVertexArray(0);
}
