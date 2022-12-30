#include "Canvas.h"
#include <opencv2/opencv.hpp>

struct Sphere {
    Sphere(cv::Point3d c, double r): c(c), r(r) {}

    cv::Point3d c;
    double r;
};

cv::Point3d canvasToViewport(cv::Point canvas) {
    return {canvas.x / 400.0 - 0.5, canvas.y / 400.0 - 0.5, 1};
}

int main() {
    Sphere spheres[] = {Sphere(cv::Point3d(0, 0, 10), 2.0), Sphere(cv::Point3d(2, 0, 4), 1)};

    Canvas canvas(400, 400);

    for(int i = 0; i < 400; i++) {
        for(int j = 0; j < 400; j++) {
            cv::Point3d viewportPoint = canvasToViewport(cv::Point(i, j));
            double min_t = std::numeric_limits<double>::infinity();
            Sphere *closest = nullptr;
            for(Sphere sphere : spheres) {
                double a = viewportPoint.dot(viewportPoint);
                double b = -2.0 * viewportPoint.dot(sphere.c);
                double c = sphere.c.dot(sphere.c) - sphere.r * sphere.r;
                double discriminant = b * b - 4 * a * c;
                if(discriminant < 0) {
                    continue;
                }
                double t1 = (-b + sqrt(discriminant)) / 2 / a, t2 = (-b - sqrt(discriminant)) / 2 / a;
                if(t1 > t2)
                    std::swap(t1, t2);

                if(t1 < min_t) {
                    min_t = t1;
                    closest = &sphere;
                }
            }
            if(closest != nullptr)
                canvas.drawPixel(i, j, 255, 0, 255);
        }
    }

    canvas.show();

    cv::waitKey(0);

    return 0;
}
