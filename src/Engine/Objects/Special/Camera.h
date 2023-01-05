//
// Created by Arthur Zhang on 12/30/22.
//

#ifndef ANAME_CAMERA_H
#define ANAME_CAMERA_H

#include <opencv2/opencv.hpp>

class Camera {
public:
    Camera();
    cv::Point3d translateToViewport(int x, int y, int w, int h);

    cv::Point3d getLocation() {
        return location;
    }

private:
    cv::Point3d location, viewport[4];
};


#endif //ANAME_CAMERA_H
