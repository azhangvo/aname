//
// Created by Arthur Zhang on 1/1/23.
//

#ifndef A_NAME_SCENE_H
#define A_NAME_SCENE_H


#include "../Objects/Lights/Light.h"
#include "../Objects/Meshes/Mesh.h"
#include <vector>

class Scene {
public:
    std::vector<Light *> *getLights() {
        return &lights;
    }

    std::vector<Mesh *> *getMeshes() {
        return &meshes;
    }

private:
    std::vector<Light *> lights;
    std::vector<Mesh *> meshes;
};


#endif //A_NAME_SCENE_H
