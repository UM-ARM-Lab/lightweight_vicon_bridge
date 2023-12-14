cmake_minimum_required(VERSION 3.8)
project(lightweight_vicon_bridge)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(CMAKE_SIZEOF_VOID_P MATCHES "8")
    set(VICON_SDK_PATH vicon_sdk/x64)
    set(VICON_SDK_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/${VICON_SDK_PATH})
    set(VICON_SDK_LINK_DIR ${PROJECT_SOURCE_DIR}/${VICON_SDK_PATH})
elseif(CMAKE_SIZEOF_VOID_P MATCHES "4")
    set(VICON_SDK_PATH vicon_sdk/x86)
    set(VICON_SDK_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/${VICON_SDK_PATH})
    set(VICON_SDK_LINK_DIR ${PROJECT_SOURCE_DIR}/${VICON_SDK_PATH})
else(CMAKE_SIZEOF_VOID_P MATCHES "8")
    message(FATAL_ERROR "Platform is not 32-bit or 64-bit - cannot link to Vicon libraries")
endif(CMAKE_SIZEOF_VOID_P MATCHES "8")


## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(include ${Boost_INCLUDE_DIRS} ${VICON_SDK_INCLUDE_DIR})
link_directories(${VICON_SDK_LINK_DIR})

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(visualization_msgs)



###########################################
############# build interfaces ############
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/MocapState.msg"
  "msg/MocapObject.msg"
  "msg/MocapSegment.msg"
  "msg/MocapMarker.msg"
  "msg/MocapMarkerArray.msg"
  DEPENDENCIES geometry_msgs std_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)
ament_export_dependencies(rosidl_default_runtime)
rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} rosidl_typesupport_cpp)
###########################################
##############  build src  ################

add_executable(lightweight_vicon_bridge_node src/lightweight_vicon_bridge_node.cpp)
ament_target_dependencies(lightweight_vicon_bridge_node rclcpp std_msgs geometry_msgs)
target_link_libraries(lightweight_vicon_bridge_node ViconDataStreamSDK_CPP "${cpp_typesupport_target}" ${Boost_LIBRARIES})


add_executable(tf_publisher_node src/tf_publisher_node.cpp)
ament_target_dependencies(tf_publisher_node rclcpp std_msgs geometry_msgs tf2 tf2_ros)
target_link_libraries(tf_publisher_node ViconDataStreamSDK_CPP "${cpp_typesupport_target}" ${Boost_LIBRARIES})

add_executable(raw_marker_bridge_node src/raw_marker_bridge_node.cpp)
ament_target_dependencies(raw_marker_bridge_node rclcpp std_msgs geometry_msgs visualization_msgs)
target_link_libraries(raw_marker_bridge_node ViconDataStreamSDK_CPP "${cpp_typesupport_target}" ${Boost_LIBRARIES})

set_target_properties(lightweight_vicon_bridge_node PROPERTIES INSTALL_RPATH "$ORIGIN;${VICON_SDK_LINK_DIR}")

#######################################
################ Install ##############

install(TARGETS
  lightweight_vicon_bridge_node
  tf_publisher_node
  raw_marker_bridge_node
  DESTINATION lib/${PROJECT_NAME})
  
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()



ament_package()
