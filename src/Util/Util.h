//
// Created by Arthur Zhang on 1/1/23.
//

#ifndef ANAME_UTIL_H
#define ANAME_UTIL_H

#include <utility>
#include <opencv2/core/types.hpp>

const double D_INF = std::numeric_limits<double>::infinity();

double clamp(double n, double lower, double upper);

#endif //ANAME_UTIL_H
