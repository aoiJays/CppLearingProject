# 指定最低版本
cmake_minimum_required(VERSION 3.15)

# 项目名
project(EmployeementManagementSystem)

# 指定C++标准
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH )
# 在CMakeLists.txt所在路径/src/中查找所有.cc后缀文件
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CNAME_MODULE_PATH ${PROJECT_SOURCE_DIR}/build)
# 指定头文件位置
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(app ${SRC})

# cmake ..
# make