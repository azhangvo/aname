cmake_minimum_required(VERSION 3.23)
set(CMAKE_OSX_ARCHITECTURES x86_64) # Comment this line out if on intel architecture I think
project(aname)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(aname main.cpp)

target_link_libraries(aname ${OpenCV_LIBS})
