cmake_minimum_required(VERSION 2.8.12)

project(ps_qt)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_definitions(-std=c++1z)

find_package(Qt5Widgets)
find_library(OPENCL_LIBRARY OpenCL)

MARK_AS_ADVANCED(OPENCL_LIBRARY)

include_directories(includes)
include_directories(CL)

file(GLOB SRC src/*.cpp)
file(GLOB INC includes/*.h CL/*.hpp)

add_executable(${PROJECT_NAME} ${SRC} ${INC})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets ${OPENCL_LIBRARY} )
