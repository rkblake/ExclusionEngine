#ifndef EE_SCENE_H
#define EE_SCENE_H

class OctTree {

};

class Scene
{
public:
    addEntity();
    UpdateEntities();
    CheckCollisions();
private:
    OctTree tree;
    std::map<unsigned int, Entity> entityList;
};

#endif
