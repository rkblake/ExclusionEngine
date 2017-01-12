#ifndef EE_COMPONENT
#define EE_COMPONENT

#include "utils/Matrix4x4f.h"

class Component {
public:
	virtual void Draw() = 0;
protected:
	Component() {}
	~Component() {}
	Matrix4x4f transform;
};

#endif
