cmake_minimum_required(VERSION 2.8.3)
project(multicam)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)
find_package(realsense2 REQUIRED)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${realsense2_INCLUDE_DIRS}
)

catkin_package()

add_executable(multicam src/multicam.cpp)

add_dependencies(multicam ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(multicam
  ${catkin_LIBRARIES}
  ${realsense2_LIBRARY}
)
