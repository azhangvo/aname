//
// Created by Arthur Zhang on 1/1/23.
//

#include "PointLight.h"

std::pair<cv::Point3d, double> PointLight::calculateLighting(cv::Point3d target) const {
    return std::make_tuple(location, getIntensity());
}
