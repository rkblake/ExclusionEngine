#ifndef EE_SCENE
#define EE_SCENE

#include "Component.h"

struct tree_node {
	Component* comp;
	tree_node* sub_nodes;
};

class Scene {
public:
	Scene() {}
	Scene(const char* script);
	~Scene() {}
private:
	tree_node* root;
};

#endif