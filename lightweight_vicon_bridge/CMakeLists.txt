cmake_minimum_required(VERSION 3.8)
project(lightweight_vicon_bridge)

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


include_directories(
  include
  ${VICON_SDK_INCLUDE_DIR}
  # vicon_sdk/x86  
  # vicon_sdk/x64             # For StreamCommon, required by ViconSDK  
)

link_directories(${VICON_SDK_LINK_DIR})

find_package(ament_cmake REQUIRED)
# find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(mocap_interfaces REQUIRED)



# set(msg_files
#   "msg/MocapState.msg"
#   "msg/MocapObject.msg"
#   "msg/MocapSegment.msg"
#   "msg/MocapMarker.msg"
#   "msg/MocapMarkerArray.msg"
# )
# rosidl_generate_interfaces(${PROJECT_NAME}
#   ${msg_files}
#   DEPENDENCIES geometry_msgs std_msgs# Add 
# )

# find dependencies


 
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


add_executable(vicon_bridge src/lightweight_vicon_bridge_node.cpp)
ament_target_dependencies(vicon_bridge rclcpp std_msgs geometry_msgs mocap_interfaces)



install(TARGETS

  vicon_bridge
  DESTINATION lib/${PROJECT_NAME})
  
  
  

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
