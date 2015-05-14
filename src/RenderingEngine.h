#ifndef EE_RENDERINGENGINE_H
#define EE_RENDERINGENGINE_H

#include <glm/glm.hpp>

class RenderingEngine
{
	friend void ComputeMatrices();
	friend glm::mat4 GetProjectionMatrix();
	friend glm::mat4 GetViewMatrix();
public:
	static inline RenderingEngine* GetInstance() {
		static RenderingEngine sRenderingEngine;
		RenderingEngine* renderer = &sRenderingEngine;
		return renderer;
	}

private:
	RenderingEngine() {}
	~RenderingEngine() {}

	//static RenderingEngine sRenderingEngine;

};

#endif
