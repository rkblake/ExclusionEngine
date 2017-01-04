#ifndef EE_COMPONENT
#define EE_COMPONENT

class Component {
public:
	virtual void Draw() = 0;
protected:
	Component() {}
	~Component() {}
};

#endif