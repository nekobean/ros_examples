cmake_minimum_required(VERSION 2.8.3)
project(service_cpp)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
   roscpp
   message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate services in the 'srv' folder
add_service_files(FILES
    AddTwoInts.srv
)

generate_messages()

###################################
## catkin specific configuration ##
###################################

catkin_package(
   CATKIN_DEPENDS roscpp message_runtime
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# server
add_executable(server_node src/server.cpp)
target_link_libraries(server_node ${catkin_LIBRARIES})
add_dependencies(server_node ${PROJECT_NAME}_gencpp)

# client
add_executable(client_node src/client.cpp)
target_link_libraries(client_node ${catkin_LIBRARIES})
add_dependencies(client_node ${PROJECT_NAME}_gencpp)
