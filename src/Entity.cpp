#include "Entity.h"

Entity::Entity(Script script) {
    uuid = uuid_counter++;
    this->script = script;

    mesh = Mesh(script.GetString("mesh"));
    shader = LoadShaders(script.GetString("vertex_shader"), script.GetString("fragment_shader"));

    GLuint MatrixID = glGetUniformLocation(shader, "MVP");
	GLuint ViewMatrixID = glGetUniformLocation(shader, "V");
	GLuint ModelMatrixID = glGetUniformLocation(shader, "M");
}

Entity::Entity(const char* path_to_script) {
    Script script = Script(path_to_script);
    Entity(script);
}

void Entity::Draw() {
    glUseProgram(shader);

    //computeMatricesFromInputs();
    //glm::mat4 ProjectionMatrix = getProjectionMatrix();
    //glm::mat4 ViewMatrix = getViewMatrix();

    glm::mat4 ModelMatrix = glm::mat4(1.0);
    glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix1;

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP1[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix1[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);

    mesh.Draw();
}
