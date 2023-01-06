#include "Engine/Objects/Special/Camera.h"
#include "Engine/Objects/Lights/PointLight.h"
#include "Engine/Render/Scene.h"
#include "Engine/Objects/Meshes/Sphere.h"
#include "Engine/Render/RayTracer.h"
#include "Engine/Objects/Lights/DirectionalLight.h"

#include <opencv2/opencv.hpp>

int main() {
    const cv::Scalar blue = {255, 0, 0}, green = {0, 255, 0}, red = {0, 0, 255};

    Camera camera;

    int w = 2048, h = 2048;
    Scene scene;

    scene.getMeshes()->push_back(new Sphere(cv::Point3d(-1, -1, 6), 1.0, Material(green, 0.5)));
    scene.getMeshes()->push_back(new Sphere(cv::Point3d(0, 3, 15), 7.0, Material(blue, 0.8)));
    scene.getMeshes()->push_back(new Sphere(cv::Point3d(0, 1.5, 6), 1.1, Material(red, 1.0)));
    scene.getLights()->push_back(new PointLight(cv::Point3d(3, 3, 1), 0.6));
    scene.getLights()->push_back(new DirectionalLight(cv::Point3d(0, 0.3, 1), 0.4));

    render_scene(scene, camera, "Canvas", w, h);

    cv::waitKey(0);

    return 0;
}