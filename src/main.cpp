#include "Engine/Objects/Special/Camera.h"
#include "Engine/Objects/Lights/PointLight.h"
#include "Engine/Render/Scene.h"
#include "Engine/Objects/Meshes/Sphere.h"
#include "Engine/Render/RayTracer.h"
#include "Engine/Objects/Lights/DirectionalLight.h"

#include <opencv2/opencv.hpp>

int main() {
    printf("Loading scene...\n\n");
    const cv::Scalar blue = {255, 0, 0}, green = {0, 255, 0}, red = {0, 0, 255};

    Camera camera;

    int w = 2048, h = 2048;
    Scene scene;

    scene.getMeshes()->push_back(new Sphere(cv::Point3d(-1, -1, 6), 1.0, Material(green, 0.8, 10, 0.2, 0)));
    scene.getMeshes()->push_back(new Sphere(cv::Point3d(0, 1, 15), 6.0, Material(blue, 0.8, 100, 0.1, 0)));
    scene.getMeshes()->push_back(new Sphere(cv::Point3d(0, 1.5, 6), 1.1, Material(red, 1, 10, 0.4, 0)));
    scene.getMeshes()->push_back(new Sphere(cv::Point3d(3, 0, 7), 2.0, Material(red + blue, 0.6, 50, 0.7, 0)));
    scene.getMeshes()->push_back(new Sphere(cv::Point3d(0, 0, 10), 1.5, Material(green + blue, 1, 200)));
    scene.getLights()->push_back(new PointLight(cv::Point3d(3, 3, 1), 0.6));
    scene.getLights()->push_back(new PointLight(cv::Point3d(-1, 6, 10), 0.3));
    scene.getLights()->push_back(new DirectionalLight(cv::Point3d(0, 0.3, 1), 0.4));

    printf("Rendering...\n\n");

    render_scene(scene, camera, "Canvas", w, h);

    printf("Done!\n");

    cv::waitKey(0);

    return 0;
}