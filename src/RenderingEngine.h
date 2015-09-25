#ifndef EE_RENDERINGENGINE_H
#define EE_RENDERINGENGINE_H

#include "Window.h"
#include "Entity.h"
#include "Shaders.h"
#include "CoreEngine.h"
#include "World.h"

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <cstring>

enum {
	FREE_LOOK,
	FIRST_PERSON,
	THIRD_PERSON
};

struct LightInfo {
    glm::vec4 Position;
    glm::vec3 La;
    glm::vec3 Ld;
    glm::vec3 Ls;
	LightInfo(glm::vec4 position, glm::vec3 la, glm::vec3 ld, glm::vec3 ls) :
		Position(position), La(la), Ld(ld), Ls(ls) {}
};

struct MaterialInfo {
    glm::vec3 Ka;
    glm::vec3 Kd;
    glm::vec3 Ks;
    float Shininess;
	MaterialInfo(glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float shininess) :
		Ka(ka), Kd(kd), Ks(ks), Shininess(shininess) {}
};

class RenderingEngine {
public:
	static inline RenderingEngine& GetInstance() {
		static RenderingEngine sRenderingEngine;
		return sRenderingEngine;
	}

	void ComputeMatrices();
	glm::mat4 GetProjectionMatrix() {return projection_matrix;}
	glm::mat4 GetViewMatrix() {return view_matrix;}
	void SetFreeLook() {camera_style = FREE_LOOK;}
	void SetFirstPerson() {camera_style = FIRST_PERSON;}
	void SetThirdPerson() {camera_style = THIRD_PERSON;}
	Window* CreateWindow(const char* title, int width, int height);
	void Init();
	void RegisterEntity(Entity* entity);
	void Swap();
	void RenderScene();
	void SetFocus(bool focus) {isFocus = focus;}
	void AttachEntity(Entity* entity) {attached_entity = entity;}
	void SetWorld(World* w) {world = w;}
private:
	Window* window;
	int _width, _height;
	glm::mat4 view_matrix, projection_matrix, model_matrix, mvp_matrix;
	GLuint viewID, projectionID, lightID, mvpID, textureID, modelViewID, materialID, normalID;
	float fov, horizontalAngle, verticalAngle;
	float mouseSpeed;
	glm::vec3 position, direction, right, up, front;
	Entity* attached_entity; //entity that the camera is attached to
	World* world;
	unsigned int camera_style;
	bool isFocus;
	std::vector<Entity*> entities;

	RenderingEngine();
	~RenderingEngine() {}
};

#endif
