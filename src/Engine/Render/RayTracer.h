//
// Created by Arthur Zhang on 1/4/23.
//

#ifndef ANAME_RAYTRACER_H
#define ANAME_RAYTRACER_H

#include <opencv2/opencv.hpp>
#include "Scene.h"
#include "../Objects/Special/Camera.h"

std::pair<Mesh *, double>
ray_intersect(Scene &scene, cv::Point3d origin, cv::Point3d vector, double t_min, double t_max);

cv::Scalar trace_ray(Scene &scene, cv::Point3d origin, cv::Point3d vector);

void render_scene(Scene scene, Camera camera, const std::string &window_name, int w, int h);

#endif //ANAME_RAYTRACER_H
