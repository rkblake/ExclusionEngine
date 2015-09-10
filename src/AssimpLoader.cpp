#include "AssimpLoader.h"

bool AssimpLoadFile(const char* filename, std::vector<glm::vec3>& vertices, std::vector<glm::vec2>& uvs, std::vector<glm::vec3>& normals) {
    printf("Loading file: %s\n", filename);
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(filename,aiProcessPreset_TargetRealtime_Fast);
    if(scene == nullptr) {
        printf("ERROR: failed to load: %s\n", filename);
        return false;
    }
    aiMesh *mesh = scene->mMeshes[0];
    //TODO: reserve space in vectors

    float* vertex_array = new float[mesh->mNumFaces*9];
    float* uv_array = new float[mesh->mNumFaces*6];
    float* normal_array = new float[mesh->mNumFaces*9];
    unsigned int numVertices = mesh->mNumFaces*3;

    for(unsigned int i = 0; i < mesh->mNumFaces; ++i) {
        const aiFace& face = mesh->mFaces[i];
        for(unsigned int j = 0; j < 3; ++j) {
            aiVector3D vertex = mesh->mVertices[face.mIndices[j]];
            vertices.push_back(glm::vec3(vertex.x, vertex.y, vertex.z));
            aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
            uvs.push_back(glm::vec2(uv.x, uv.y));
            aiVector3D normal = mesh->mNormals[face.mIndices[j]];
            normals.push_back(glm::vec3(normal.x, normal.y, normal.z));
        }
    }

    printf("SUCCESS\n");
    return true;
}
