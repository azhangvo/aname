cmake_minimum_required(VERSION 3.23)
set(CMAKE_OSX_ARCHITECTURES x86_64) # Comment this line out if on intel architecture I think
project(aname)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(aname src/main.cpp src/Display/Canvas.cpp src/Display/Canvas.h src/Engine/Objects/Special/Camera.cpp src/Engine/Objects/Special/Camera.h src/Engine/Render/Scene.cpp src/Engine/Render/Scene.h src/Engine/Objects/Lights/Light.cpp src/Engine/Objects/Lights/Light.h src/Engine/Objects/Lights/PointLight.cpp src/Engine/Objects/Lights/PointLight.h src/Engine/Objects/Meshes/Mesh.cpp src/Engine/Objects/Meshes/Mesh.h src/Engine/Materials/Material.cpp src/Engine/Materials/Material.h src/Util/Util.cpp src/Util/Util.h src/Engine/Objects/Meshes/Sphere.cpp src/Engine/Objects/Meshes/Sphere.h src/Engine/Render/Scene.fwd.h src/Engine/Render/RayTracer.cpp src/Engine/Render/RayTracer.h src/Engine/Objects/Lights/DirectionalLight.cpp src/Engine/Objects/Lights/DirectionalLight.h)

target_link_libraries(aname ${OpenCV_LIBS})
