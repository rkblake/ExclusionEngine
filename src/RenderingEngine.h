#ifndef EE_RENDERINGENGINE_H
#define EE_RENDERINGENGINE_H

#include "Window.h"

#include <glm/glm.hpp>

class RenderingEngine {
public:
	static inline RenderingEngine& GetInstance() {
		static RenderingEngine sRenderingEngine;
		return sRenderingEngine;
	}

	void ComputeMatrices();
	glm::mat4 GetProjectionMatrix();
	glm::mat4 GetViewMatrix();
	void CreateWindow(const char* title, int width, int height);
	void Swap();
private:
	Window window;

	RenderingEngine() {}
	~RenderingEngine() {}

	//static RenderingEngine sRenderingEngine;

};

#endif
