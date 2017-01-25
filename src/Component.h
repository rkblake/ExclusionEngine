#ifndef EE_COMPONENT
#define EE_COMPONENT

#include "utils/Matrix4x4f.h"
#include "Script.h"

class Component {
public:
	virtual void Draw() = 0;
	Matrix4x4f getModelMatrix() {return transform;}
protected:
	Component() {}
	~Component() {}
	Matrix4x4f transform;
	Script* script;
};

#endif
