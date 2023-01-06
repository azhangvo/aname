//
// Created by Arthur Zhang on 1/4/23.
//

#include "RayTracer.h"
#include "../../Display/Canvas.h"
#include "../../Util/Util.h"

cv::Point3d reflect(cv::Point3d vector, cv::Point3d normal) {
    return 2 * normal * vector.dot(normal) - vector;
}

std::pair<Mesh *, double>
ray_intersect(Scene &scene, cv::Point3d origin, cv::Point3d vector, double t_min, double t_max) {
    double closest_t = NAN;
    Mesh *closest_mesh = nullptr;
    for (Mesh *mesh: *scene.getMeshes()) {
        double t = mesh->intersectsRay(origin, vector, t_min, t_max);
        if (isnan(t) || t < t_min || t > t_max)
            continue;

        if (isnan(closest_t) || t < closest_t) {
            closest_t = t;
            closest_mesh = mesh;
        }
    }

    return std::make_pair(closest_mesh, closest_t);
}

cv::Scalar trace_ray(Scene &scene, cv::Point3d origin, cv::Point3d vector, int max_depth) {
    auto intersect_data = ray_intersect(scene, origin, vector, 1, D_INF);

    Mesh *mesh = intersect_data.first;
    if (mesh == nullptr) {
        return {0, 0, 0};
    }

    double t = intersect_data.second;
    cv::Point3d intersection = origin + vector * t;
    cv::Point3d normal = mesh->normal(intersection);
    cv::Point3d view_vector = -vector / norm(vector);

    const Material *material = &mesh->getMaterial();

    cv::Scalar color;

    double ambient = 0;

    double diffuse = 0;
    double specular = 0;
    double specular_coefficient = material->getSpecular();
    for (Light *light: *scene.getLights()) {
        auto lighting = light->calculateLighting(intersection);
        auto light_intersect_data = ray_intersect(scene, lighting.first, intersection - lighting.first, 0, 1);

        if (light_intersect_data.first != nullptr && light_intersect_data.first != mesh)
            continue;

        cv::Point3d light_incident = lighting.first - intersection;
        light_incident /= norm(light_incident);
        double raw_diffuse = light_incident.dot(normal);
        if (raw_diffuse > 0)
            diffuse += raw_diffuse * light->getIntensity();

        if (specular_coefficient > 0) {
            cv::Point3d reflection = reflect(light_incident, normal);
            double raw_spec = reflection.dot(view_vector);
            if (raw_spec > 0)
                specular += std::pow(raw_spec, specular_coefficient) * light->getIntensity();
        }
    }

    double direct = ambient + diffuse * material->getDiffuse() + specular;
    color += direct * material->getColor();

    double reflective = material->getReflective();
    if (max_depth > 0 && reflective > 0) {
        cv::Point3d reflection_vector = reflect(view_vector, normal);
        cv::Scalar reflection = trace_ray(scene, intersection, reflection_vector, max_depth - 1);
        color += reflection * reflective;
    }

    return color;
}

void render_scene(Scene scene, Camera camera, const std::string &window_name, int w, int h) {
    Canvas canvas(w, h, window_name);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cv::Point3d viewportPoint = camera.translateToViewport(i, j, w, h);
            canvas.drawPixel(i, j, trace_ray(scene, camera.getLocation(), viewportPoint, 3));
        }
    }

    canvas.show();
}
