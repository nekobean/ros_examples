cmake_minimum_required(VERSION 2.8.3)
project(webcam)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
   roscpp
   cv_bridge
   sensor_msgs
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
   CATKIN_DEPENDS roscpp
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# server
add_executable(image_subscriber_node
    src/image_subscriber.cpp
)

target_link_libraries(image_subscriber_node
    ${catkin_LIBRARIES}
)

add_dependencies(image_subscriber_node
    ${PROJECT_NAME}_gencpp
)
