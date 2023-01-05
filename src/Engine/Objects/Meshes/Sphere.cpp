//
// Created by Arthur Zhang on 1/2/23.
//

#include "Sphere.h"

double Sphere::intersectsRay(cv::Point3d start, cv::Point3d direction, double min_t, double max_t) const {
    double a = direction.dot(direction);
    double b = -2.0 * direction.dot(location);
    double c = location.dot(location) - radius * radius;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return NAN;
    }
    double t1 = (-b + sqrt(discriminant)) / 2 / a, t2 = (-b - sqrt(discriminant)) / 2 / a;
    double t = NAN;

    if(t1 >= min_t && t1 <= max_t)
        t = t1;
    if(t2 >= min_t && t2 <= max_t && (isnan(t) || t2 < t))
        t = t2;

    return t;
}

cv::Point3d Sphere::normal(cv::Point3d intersection) {
    auto normal = intersection - location;
    normal /= norm(normal);
    return normal;
}
