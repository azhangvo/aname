//
// Created by Arthur Zhang on 1/2/23.
//

#ifndef A_NAME_SPHERE_H
#define A_NAME_SPHERE_H


#include <utility>

#include "Mesh.h"

class Sphere : public Mesh {
public:
    Sphere(cv::Point3d location, double radius) : Mesh(location), radius(radius) {};

    Sphere(cv::Point3d location, double radius, Material material) : Mesh(location, std::move(material)),
                                                                     radius(radius) {};

    double intersectsRay(cv::Point3d start, cv::Point3d direction, double min_t, double max_t) const override;

    cv::Point3d normal(cv::Point3d intersection) override;

private:
    double radius;

};


#endif //A_NAME_SPHERE_H
