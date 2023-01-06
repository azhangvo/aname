//
// Created by Arthur Zhang on 1/1/23.
//

#ifndef A_NAME_MATERIAL_H
#define A_NAME_MATERIAL_H


#include <opencv2/opencv.hpp>
#include <utility>

class Material {
public:
    Material() = default;

    explicit Material(cv::Scalar color) : color(std::move(color)) {};

    explicit Material(cv::Scalar color, double diffuse) : color(std::move(color)), diffuse(diffuse) {};

    explicit Material(cv::Scalar color, double diffuse, double specular) : color(std::move(color)), diffuse(diffuse),
                                                                           specular(specular) {};

    explicit Material(cv::Scalar color, double diffuse, double specular, double reflective, double transparent) : color(
            std::move(color)), diffuse(diffuse), specular(specular), reflective(reflective), transparent(
            transparent) {};

    const cv::Scalar &getColor() const { return color; }

    double getDiffuse() const { return diffuse; }

    double getSpecular() const { return specular; }

    double getReflective() const { return reflective; }

    double getTransparent() const { return transparent; }

private:
    cv::Scalar color;
    double diffuse{0}, specular{0}, reflective{0}, transparent{0};
};


#endif //A_NAME_MATERIAL_H
