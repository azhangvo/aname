//
// Created by Arthur Zhang on 12/30/22.
//

#include "Canvas.h"

#include "../Util/Util.h"

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
    auto &pixel = mat.at<cv::Vec3b>(
            cv::Point(x, y)); // one comment says to use .ptr instead of .at for performance, will revisit
    double b = round(color[0]), g = round(color[1]), r = round(color[2]);
    pixel[0] = (int) clamp(b, 0, 255);
    pixel[1] = (int) clamp(g, 0, 255);
    pixel[2] = (int) clamp(r, 0, 255);
}

void Canvas::drawPixel(int x, int y, int r, int g, int b) {
    auto &pixel = mat.at<cv::Vec3b>(cv::Point(x, y));
    pixel[0] = (int) clamp(b, 0, 255);
    pixel[1] = (int) clamp(g, 0, 255);
    pixel[2] = (int) clamp(r, 0, 255);
}

void Canvas::show() {
    cv::imshow(name, mat);
}