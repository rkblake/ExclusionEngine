#include "Entity.h"

/*Entity::Entity(Script script) {
    uuid = uuid_counter++;
    this->script = script;

    mesh = Mesh(script.GetString("mesh"));
    shader = LoadShaders(script.GetString("vertex_shader"), script.GetString("fragment_shader"));

    MatrixID = glGetUniformLocation(shader, "MVP");
	ViewMatrixID = glGetUniformLocation(shader, "V");
	ModelMatrixID = glGetUniformLocation(shader, "M");
}*/

Entity::Entity(const char* path_to_script) {
    this->script = Script(path_to_script);

    mesh = Mesh(script.GetString("mesh"));
    //shader = LoadShaders(script.GetString("vertex_shader"), script.GetString("fragment_shader"));

    //MatrixID = glGetUniformLocation(shader, "MVP");
    //ViewMatrixID = glGetUniformLocation(shader, "V");
    //ModelMatrixID = glGetUniformLocation(shader, "M");
}

void Entity::Draw() {
    //glUseProgram(shader);



    mesh.Draw();
}
