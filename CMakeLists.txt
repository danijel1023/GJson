cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 17)

project(GJson VERSION 0.1)


file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_library(GJson STATIC ${SRC_FILES})

target_include_directories(GJson PUBLIC "include")

add_subdirectory("Test_Application")
