//
// Created by Arthur Zhang on 1/1/23.
//

#ifndef ANAME_SCENE_H
#define ANAME_SCENE_H


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


#endif //ANAME_SCENE_H
