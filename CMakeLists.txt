cmake_minimum_required(VERSION 3.0.0)
project(LeviathanEngine VERSION 0.0.2 LANGUAGES C CXX)

include(CTest)
enable_testing()

# SET(CMAKE_CXX_FLAGS "-mwindows")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(LeviathanEngine-Shipping main.cpp src/draw/draw2d.cpp)

target_link_libraries(LeviathanEngine-Shipping ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#
# Debug Build
#

project(LeviathanEngine VERSION 0.0.2 LANGUAGES C CXX)

enable_testing()

# SET(CMAKE_CXX_FLAGS "-mwindows")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(LeviathanEngine-Debug main_d.cpp src/draw/draw2d.cpp)

target_link_libraries(LeviathanEngine-Debug ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
 