#include "Engine/Canvas.h"
#include "Engine/Camera.h"
#include <opencv2/opencv.hpp>
#include <utility>

struct Sphere {
    Sphere(cv::Point3d c, double r, cv::Scalar color) : c(c), r(r), color(std::move(color)) {}

    cv::Point3d c;
    double r;
    cv::Scalar color;
};

struct PointLight {
    PointLight(cv::Point3d c, double i) : c(c), intensity(i) {};

    cv::Point3d c;
    double intensity;
};

int main() {
    const cv::Scalar blue = {255, 0, 0}, green = {0, 255, 0}, red = {0, 0, 255};

    Sphere spheres[] = {Sphere(cv::Point3d(0, 0, 10), 2.0, blue), Sphere(cv::Point3d(2, 0, 4), 1, red)};
    PointLight lights[] = {PointLight(cv::Point3d(3, 3, 1), 0.8)};
    Camera camera;

    int w = 2048, h = 2048;
    double ambient = 0.2;
    Canvas canvas(w, h);
    camera.setResolution(w, h);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cv::Point3d viewportPoint = camera.translateToViewport(i, j);
            double min_t = std::numeric_limits<double>::infinity();
            Sphere *closest = nullptr;
            for (Sphere &sphere: spheres) {
                double a = viewportPoint.dot(viewportPoint);
                double b = -2.0 * viewportPoint.dot(sphere.c);
                double c = sphere.c.dot(sphere.c) - sphere.r * sphere.r;
                double discriminant = b * b - 4 * a * c;
                if (discriminant < 0) {
                    continue;
                }
                double t1 = (-b + sqrt(discriminant)) / 2 / a, t2 = (-b - sqrt(discriminant)) / 2 / a;
                if (t1 > t2)
                    std::swap(t1, t2);

                if (t1 >= 1 && t1 < min_t) {
                    min_t = t1;
                    closest = &sphere;
                }
                if (t2 >= 1 && t2 < min_t) {
                    min_t = t2;
                    closest = &sphere;
                }
            }
            if (closest != nullptr) {
                cv::Point3d intersection = min_t * viewportPoint;
                cv::Point3d normal = intersection - closest->c;
                normal /= norm(normal);
                double illumination = ambient;
                for(auto light : lights) {
                    cv::Point3d vec = light.c - intersection;
                    double contrib = vec.dot(normal) / norm(vec);
                    if(contrib > 0)
                        illumination += contrib;
                }
                canvas.drawPixel(i, j, closest->color * illumination);
            } else
                canvas.drawPixel(i, j, 255, 255, 255);
        }
    }

    canvas.show();

    cv::waitKey(0);

    return 0;
}
