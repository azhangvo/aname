//
// Created by Arthur Zhang on 1/1/23.
//

#ifndef A_NAME_POINTLIGHT_H
#define A_NAME_POINTLIGHT_H


#include <opencv2/opencv.hpp>
#include "Light.h"

class PointLight : public Light {
public:
    PointLight(cv::Point3d location, double intensity) : location(location), Light(intensity) {};

    cv::Point3d getLocation() const {
        return location;
    }

    std::pair<cv::Point3d, double> calculateLighting(cv::Point3d target) const override;

private:
    cv::Point3d location;
};


#endif //A_NAME_POINTLIGHT_H
