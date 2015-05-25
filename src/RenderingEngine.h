#ifndef EE_RENDERINGENGINE_H
#define EE_RENDERINGENGINE_H

#include "Window.h"
#include "Entity.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <SDL2/SDL.h>

enum {
	FREE_LOOK,
	FIRST_PERSON,
	THIRD_PERSON
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
	void Swap();
private:
	Window window;
	int _width, _height;
	glm::mat4 view_matrix;
	glm::mat4 projection_matrix;
	float fov, horizontalAngle, verticalAngle;
	float mouseSpeed;
	glm::vec3 position, direction, right, up, front;
	Entity* attached_entity; //entity that the camera is attached
	unsigned int camera_style;
	bool isFocus;

	RenderingEngine() {
		mouseSpeed = 0.005f;
		fov = 45.0f;
		camera_style = FIRST_PERSON;
	}
	~RenderingEngine() {}
};

#endif
