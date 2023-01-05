//
// Created by Arthur Zhang on 1/1/23.
//

#ifndef ANAME_MATERIAL_H
#define ANAME_MATERIAL_H


#include <opencv2/opencv.hpp>
#include <utility>

class Material {
public:
    Material() = default;

    explicit Material(cv::Scalar color) : color(std::move(color)) {};

    explicit Material(cv::Scalar color, double specular) : color(std::move(color)), specular(specular) {};

    explicit Material(cv::Scalar color, double specular, double reflective, double transparent) : color(
            std::move(color)), specular(specular), reflective(reflective), transparent(transparent) {};

    const cv::Scalar &getColor() const { return color; }

    double getSpecular() const { return specular; }

    double getReflective() const { return reflective; }

    double getTransparent() const { return transparent; }

private:
    cv::Scalar color;
    double specular{0}, reflective{0}, transparent{0};
};


#endif //ANAME_MATERIAL_H
