//
// Created by Arthur Zhang on 1/5/23.
//

#ifndef A_NAME_DIRECTIONALLIGHT_H
#define A_NAME_DIRECTIONALLIGHT_H


#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight(cv::Point3d direction, double intensity) : direction(direction / norm(direction)), Light(intensity) {};

    std::pair<cv::Point3d, double> calculateLighting(cv::Point3d target) const override;

private:
    cv::Point3d direction;
    double t_max = 1e5;
};


#endif //A_NAME_DIRECTIONALLIGHT_H
