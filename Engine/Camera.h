//
// Created by Arthur Zhang on 12/30/22.
//

#ifndef ANAME_CAMERA_H
#define ANAME_CAMERA_H

#include <opencv2/opencv.hpp>

class Camera {
public:
    Camera();
    void setResolution(int width, int height);
    cv::Point3d translateToViewport(int x, int y);

    cv::Point3d getLocation() {
        return location;
    }
    int getWidth() const {
        return w;
    }
    int getHeight() const {
        return h;
    }

private:
    cv::Point3d location, viewport[4];
    int w{-1}, h{-1};
};


#endif //ANAME_CAMERA_H
