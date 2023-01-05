//
// Created by Arthur Zhang on 12/30/22.
//

#ifndef ANAME_CANVAS_H
#define ANAME_CANVAS_H


#include <opencv2/opencv.hpp>

class Canvas {
public:
    Canvas(int w, int h, std::string name="Canvas");
    cv::Mat getMat();
    int getWidth() const;
    int getHeight() const;
    void clear();
    void drawPixel(int x, int y, cv::Scalar color);
    void drawPixel(int x, int y, int r, int g, int b);
    void show();

private:
    cv::Mat mat;
    int w, h;
    std::string name;
};


#endif //ANAME_CANVAS_H
