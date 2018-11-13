cmake_minimum_required(VERSION 3.12)
project(include)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(include
    .idea/include.iml
    .idea/misc.xml
    .idea/modules.xml
    .idea/workspace.xml
    cmake-build-debug/cmake_install.cmake
    cmake-build-debug/CMakeCache.txt
    cmake-build-debug/include.cbp
    cmake-build-debug/Makefile
    Action.h
    CMakeLists.txt
    Customer.h
    Dish.h
    Restaurant.h
    Table.h)
