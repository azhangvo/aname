//
// Created by Arthur Zhang on 1/5/23.
//

#include "DirectionalLight.h"
#include "../../../Util/Util.h"

std::pair<cv::Point3d, double> DirectionalLight::calculateLighting(cv::Point3d target) const {
    double t = D_INF;
    if(direction.x != 0)
        t = (t_max - std::abs(target.x)) / direction.x;
    if(direction.y != 0)
        t = std::min(t, (t_max - std::abs(target.y)) / direction.y);
    if(direction.z != 0)
        t = std::min(t, (t_max - std::abs(target.z)) / direction.z);
    return {target - direction * t, getIntensity()};
}
