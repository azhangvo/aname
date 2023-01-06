//
// Created by Arthur Zhang on 1/1/23.
//

#ifndef A_NAME_MESH_H
#define A_NAME_MESH_H


#include <opencv2/opencv.hpp>
#include <utility>
#include "../../Materials/Material.h"

class Mesh {
public:
    explicit Mesh(cv::Point3d location) : location(location), material() {};

    Mesh(cv::Point3d location, Material material) : location(location), material(std::move(material)) {};

    void setMaterial(Material m) { this->material = std::move(m); };

    const Material &getMaterial() const { return material; }

    virtual double intersectsRay(cv::Point3d start, cv::Point3d direction, double min_t, double max_t) const = 0;

    virtual cv::Point3d normal(cv::Point3d intersection) = 0;

private:
    Material material;
protected:
    cv::Point3d location;
};


#endif //A_NAME_MESH_H
