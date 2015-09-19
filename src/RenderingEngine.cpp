#include "RenderingEngine.h"

#include <btBulletDynamicsCommon.h>

RenderingEngine::RenderingEngine() {
	mouseSpeed = 0.0005f;
	fov = 45.0f;
	camera_style = FREE_LOOK;
	isFocus = true;

/*	GLuint shader = LoadShaders("res/vertex.shader", "res/fragment.shader");
	glUseProgram(shader);
	glm::vec3 lightPos(0, 5, 0);
	GLuint projectionID = glGetUniformLocation(shader, "P");
	GLuint viewID = glGetUniformLocation(shader, "V");
	GLuint lightPosID = glGetUniformLocation(shader, "LightPosition_worldspace");
	GLuint MvpID = glGetUniformLocation(shader, "MVP");
	GLuint TextureID = glGetUniformLocation(shader, "texture_sampler");

	glUniform3f(lightPosID, lightPos.x, lightPos.y, lightPos.z);
*/
}

void RenderingEngine::Init() {

	GLuint shader = LoadShaders("res/ADS.vs", "res/ADS.fs");
	glUseProgram(shader);
	modelViewID = glGetUniformLocation(shader, "ModelViewMatrix");
	viewID = glGetUniformLocation(shader, "ViewMatrix");
	//lightID = glGetUniformLocation(shader, "Light");
	mvpID = glGetUniformLocation(shader, "MVP");
	textureID = glGetUniformLocation(shader, "texture_sampler");
	normalID = glGetUniformLocation(shader, "NormalMatrix");
	modelViewID = glGetUniformLocation(shader, "ModelViewMatrix");
	projectionID = glGetUniformLocation(shader, "ProjectionMatrix");
	//materialID = glGetUniformLocation(shader, "Material");

	LightInfo light = LightInfo(glm::vec4(1.0,1.0,1.0, 0.0), glm::vec3(0.05), glm::vec3(0.05), glm::vec3(0.05));
	MaterialInfo material = MaterialInfo(glm::vec3(0.05), glm::vec3(0.05), glm::vec3(0.05), 0.2);

	const char* blockNames[] = {"Light", "Material"};
	const char* lightNames[] = {"Position", "La", "Ld", "Ls"};
	const char* materialNames[] = {"Ka", "Kd", "Ks", "Shininess"};
	GLuint ubo[2];
	glGenBuffers(2, ubo);
	for(unsigned int i = 0; i < 2; ++i) {
		GLuint blockIndex;
		GLint blockSize;
		blockIndex = glGetUniformBlockIndex(shader, blockNames[i]);
		glGetActiveUniformBlockiv(shader, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &blockSize);
		GLubyte* blockBuffer = new GLubyte[blockSize];
		GLuint indices[4];
		GLint offsets[4];
		glBindBuffer(GL_UNIFORM_BUFFER, ubo[i]);
		if(i == 0) {
			glGetUniformIndices(shader, 4, lightNames, indices);
			glGetActiveUniformsiv(shader, 4, indices, GL_UNIFORM_OFFSET, offsets);
			std::memcpy(blockBuffer + offsets[0], (void*)&light.Position, sizeof(glm::vec4));
			std::memcpy(blockBuffer + offsets[1], (void*)&light.La, sizeof(glm::vec3));
			std::memcpy(blockBuffer + offsets[2], (void*)&light.Ld, sizeof(glm::vec3));
			std::memcpy(blockBuffer + offsets[3], (void*)&light.Ls, sizeof(glm::vec3));
		}
		else {
			glGetUniformIndices(shader, 4, materialNames, indices);
			glGetActiveUniformsiv(shader, 4, indices, GL_UNIFORM_OFFSET, offsets);
			std::memcpy(blockBuffer + offsets[0], (void*)&material.Ka, sizeof(glm::vec3));
			std::memcpy(blockBuffer + offsets[1], (void*)&material.Kd, sizeof(glm::vec3));
			std::memcpy(blockBuffer + offsets[2], (void*)&material.Ks, sizeof(glm::vec3));
			std::memcpy(blockBuffer + offsets[3], (void*)&material.Shininess, sizeof(GLfloat));
		}
		glBufferData(GL_UNIFORM_BUFFER, blockSize, blockBuffer, GL_DYNAMIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, blockIndex, ubo[i]);
		delete [] blockBuffer;
	}

	glUniform1i(textureID, 0);

}

void RenderingEngine::ComputeMatrices() {
    int x_pos, y_pos;
    SDL_GetMouseState(&x_pos, &y_pos);

    if(isFocus) {
        SDL_WarpMouseInWindow(window->GetWindow(), _width/2, _height/2);
        horizontalAngle += mouseSpeed * (_width/2 - x_pos);
        verticalAngle += mouseSpeed * (_height/2 - y_pos);
    }

    if(camera_style == FREE_LOOK) {
		position = glm::vec3(0, 10, -50);

        direction = glm::vec3(
    		cos(verticalAngle) * sin(horizontalAngle),
    		sin(verticalAngle),
    		cos(verticalAngle) * cos(horizontalAngle)
    	);
		//printf("<%.2f, %.2f, %.2f>\n", direction.x, direction.y, direction.z);

		//direction = glm::vec3(0, 0, 1);
        right = glm::vec3(
    		sin(horizontalAngle - 3.14f/2.0f),
    		0,
    		cos(horizontalAngle - 3.14f/2.0f)
    	);

    	front = glm::vec3(
    		sin(horizontalAngle - 3.14f/2.0f),
    		0,
    		0);

        up = glm::vec3(0,1,0);

        projection_matrix = glm::perspective(fov, 4.0f / 3.0f, 0.1f, 100.0f);
		//btTransform entity_pos;
		//attached_entity->GetRigidBody()->getMotionState()->getWorldTransform(entity_pos);
		//btVector3 entity_vec = entity_pos.getOrigin();
		//position = glm::vec3(entity_vec.x(), entity_vec.y(), entity_vec.z());
		//view_matrix = glm::lookAt(position, position, up);
    	view_matrix = glm::lookAt(position, position+direction, up);
    }
    else if(camera_style == FIRST_PERSON) {
        //direction = attached_entity->GetDirection();
        //float
        //right = glm::vec3()

    }
    else {

    }
}

Window* RenderingEngine::CreateWindow(const char* title, int width, int height) {
    //probably better to grab values from config script here than from inside main
    _width = width;
    _height = height;
    window = new Window(title, width, height);
    return window;
}

void RenderingEngine::RegisterEntity(Entity* entity) {
	entities.push_back(entity);
}

void RenderingEngine::Swap() {
    window->SwapBuffers();
}

void RenderingEngine::RenderScene() {
	ComputeMatrices();
	//view_matrix = glm::translate(glm::mat4(1.0), glm::vec3(0, -15, -50.0));
	view_matrix = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, -5.0));
	model_matrix = glm::mat4(1.0);
	glm::mat4 modelViewMatrix = view_matrix * model_matrix;
	glm::mat4 normalMatrix = glm::transpose(glm::inverse(modelViewMatrix));
	glUniformMatrix4fv(viewID, 1, GL_FALSE, &view_matrix[0][0]);
	glUniformMatrix4fv(projectionID, 1, GL_FALSE, &projection_matrix[0][0]);
	glUniformMatrix4fv(normalID, 1, GL_FALSE, &normalMatrix[0][0]);
	glUniformMatrix4fv(modelViewID, 1, GL_FALSE, &modelViewMatrix[0][0]);

	for(std::vector<Entity*>::iterator i = entities.begin(); i != entities.end(); ++i) {
		if((*i) == attached_entity && camera_style == FIRST_PERSON)
			continue;	//don't render attached entity in first person
		btTransform entity_pos;
		attached_entity->GetRigidBody()->getMotionState()->getWorldTransform(entity_pos);
		btVector3 entity_vec = entity_pos.getOrigin();
		//model_matrix = glm::translate(glm::mat4(1.0), glm::vec3(entity_vec.x(), entity_vec.y(), entity_vec.z()));
		mvp_matrix = projection_matrix * view_matrix * model_matrix;
		glUniformMatrix4fv(mvpID, 1, GL_FALSE, &mvp_matrix[0][0]);
		(*i)->Draw();
	}
}
