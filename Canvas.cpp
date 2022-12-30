//
// Created by Arthur Zhang on 12/30/22.
//

#include "Canvas.h"

#include <utility>

cv::Mat Canvas::getMat() {
    return mat;
}

void Canvas::clear() {
    mat = cv::Scalar(0, 0, 0);
}

Canvas::Canvas(int w, int h, std::string name) {
    mat = cv::Mat(h, w, CV_8UC3);
    this->w = w;
    this->h = h;
    this->name = std::move(name);
}

int Canvas::getWidth() const {
    return w;
}

int Canvas::getHeight() const {
    return h;
}

void Canvas::drawPixel(int x, int y, cv::Scalar color) {
    auto &pixel = mat.at<cv::Vec3b>(cv::Point(x, y));
    int b = (int) round(color[0]), g = (int) round(color[1]), r = (int) round(color[2]);
    pixel[0] = b;
    pixel[1] = g;
    pixel[2] = r;
}

void Canvas::drawPixel(int x, int y, int r, int g, int b) {
    auto &pixel = mat.at<cv::Vec3b>(cv::Point(x, y));
    pixel[0] = b;
    pixel[1] = g;
    pixel[2] = r;
}

void Canvas::show() {
    cv::imshow(name, mat);
}
