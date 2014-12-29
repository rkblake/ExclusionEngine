#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include "ExclusionEngine.h"

class RenderingEngine : public CoreEngine {
public:
	static inline RenderingEngine* GetInstance() {return new RenderingEngine;}
private:
	RenderingEngine() {}
	~RenderingEngine() {}
};

#endif
