#ifndef EE_RENDERINGENGINE_H
#define EE_RENDERINGENGINE_H

//#include "ExclusionEngine.h"

class RenderingEngine
{
public:
	static inline RenderingEngine* GetInstance()
	{
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
