#include "Entity.h"

Entity::Entity(Script script) {
    /*uuid = uuid_counter++;
    this->script = script;

    mesh = Mesh(script.GetString("mesh"));
    shader = LoadShaders(script.GetString("vertex_shader"), script.GetString("fragment_shader"));

    MatrixID = glGetUniformLocation(shader, "MVP");
	ViewMatrixID = glGetUniformLocation(shader, "V");
	ModelMatrixID = glGetUniformLocation(shader, "M");*/
}

Entity::Entity(const char* path_to_script) {
    this->script = script;

    mesh = Mesh(script.GetString("mesh"));
    shader = LoadShaders(script.GetString("vertex_shader"), script.GetString("fragment_shader"));

    MatrixID = glGetUniformLocation(shader, "MVP");
    ViewMatrixID = glGetUniformLocation(shader, "V");
    ModelMatrixID = glGetUniformLocation(shader, "M");
}

void Entity::Draw() {
    glUseProgram(shader);

    //computeMatricesFromInputs();
    //glm::mat4 ProjectionMatrix = getProjectionMatrix();
    //glm::mat4 ViewMatrix = getViewMatrix();

    glm::mat4 ModelMatrix = glm::mat4(1.0);
    //glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

    //glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    //glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
    //glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);

    mesh.Draw();
}
