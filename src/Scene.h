#ifndef EE_SCENE
#define EE_SCENE

struct tree_node {

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