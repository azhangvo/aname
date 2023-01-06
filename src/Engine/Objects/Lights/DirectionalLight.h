//
// Created by Arthur Zhang on 1/5/23.
//

#ifndef ANAME_DIRECTIONALLIGHT_H
#define ANAME_DIRECTIONALLIGHT_H


#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight(cv::Point3d direction, double intensity) : direction(direction), Light(intensity) {};

    std::pair<cv::Point3d, double> calculateLighting(cv::Point3d target) const override;

private:
    cv::Point3d direction;
};


#endif //ANAME_DIRECTIONALLIGHT_H
