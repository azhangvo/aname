//
// Created by Arthur Zhang on 1/1/23.
//

#include "Util.h"

//std::pair<double, double> trace_ray(cv::Point3d start, cv::Point3d direction) {
//    double a = viewportPoint.dot(viewportPoint);
//    double b = -2.0 * viewportPoint.dot(sphere.c);
//    double c = sphere.c.dot(sphere.c) - sphere.r * sphere.r;
//    double discriminant = b * b - 4 * a * c;
//    if (discriminant < 0) {
//        continue;
//    }
//    double t1 = (-b + sqrt(discriminant)) / 2 / a, t2 = (-b - sqrt(discriminant)) / 2 / a;
//
//    return std::pair<double, double>();
//}

double clamp(double n, double lower, double upper) {
    return std::max(lower, std::min(n, upper));
}