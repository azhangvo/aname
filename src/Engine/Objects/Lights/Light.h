//
// Created by Arthur Zhang on 1/1/23.
//

#ifndef ANAME_LIGHT_H
#define ANAME_LIGHT_H

#include <utility>
#include "opencv2/opencv.hpp"
#include "../../Render/Scene.fwd.h"

class Light {
public:
    explicit Light(double intensity) : intensity(intensity) {};

    virtual std::pair<cv::Point3d, double> calculateLighting(cv::Point3d target) const = 0;

    double getIntensity() const {
        return intensity;
    }

private:
    double intensity;
};


#endif //ANAME_LIGHT_H
