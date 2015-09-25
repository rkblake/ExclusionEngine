#ifndef EE_UTILS
#define EE_UTILS

#include <glm/glm.hpp>
#include <bullet/LinearMath/btVector3.h>

btVector3& glmToBulletVec(glm::vec3& glm_vec) {
    return new btVector3(glm_vec.x, glm_vec.y, glm_vec.z);
}

#endif
