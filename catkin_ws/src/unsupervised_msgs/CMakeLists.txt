cmake_minimum_required(VERSION 2.8.3)
project(unsupervised_msgs)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  rospy
  std_msgs
)
catkin_python_setup()

add_service_files(
    FILES
    NavigatorCmd.srv
    )

generate_messages(
    DEPENDENCIES
    std_msgs
    )

catkin_package(
    CATKIN_DEPENDS message_runtime std_msgs)

