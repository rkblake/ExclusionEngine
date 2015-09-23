#ifndef EE_ASSIMPLOADER
#define EE_ASSIMPLOADER

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/cimport.h>
#include <stdio.h>
#include <vector>
#include <glm/glm.hpp>

bool AssimpLoadFile(
    const char* filename,
    std::vector<glm::vec3>& vertices,
    std::vector<glm::vec2>& uvs,
    std::vector<glm::vec3>& normals
    //std::vector<unsigned short>& indices
);

#endif
