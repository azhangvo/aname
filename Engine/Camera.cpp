//
// Created by Arthur Zhang on 12/30/22.
//

#include "Camera.h"

Camera::Camera() {
    location = cv::Point3d(0, 0, 0);
    viewport[0] = cv::Point3d(-0.5, 0.5, 1);
    viewport[1] = cv::Point3d(0.5, 0.5, 1);
    viewport[2] = cv::Point3d(0.5, -0.5, 1);
    viewport[3] = cv::Point3d(-0.5, -0.5, 1);
}

void Camera::setResolution(int width, int height) {
    this->w = width;
    this->h = height;
}

cv::Point3d Camera::translateToViewport(int x, int y) {
    cv::Point3d x_vec = viewport[1] - viewport[0], y_vec = viewport[3] - viewport[0];
    return viewport[0] + x_vec * x / w + y_vec * y / h;
}
