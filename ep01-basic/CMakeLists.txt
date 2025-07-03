# 指定构建项目所需的最低版本
cmake_minimum_required(VERSION 3.28)

# 定义项目的名称、版本、描述和语言支持
project(ep01_basic VERSION 1.0.0 DESCRIPTION "A simple cmake project" LANGUAGES CXX)

# 指定项目使用的C++标准版本
set(CMAKE_CXX_STANDARD 17)

# 指定是否强制要求使用CMAKE_CXX_STANDARD设置的C++标准版本
set(CMAKE_CXX_STANDARD_REQUIRED True)


configure_file(MainConfig.h.in config.h)

add_subdirectory(MathFunctions)

# 定一个可执行文件的名称及其所需的源文件，在构建时会将这些源文件编译并链接为一个可执行程序
add_executable(ep01_basic main.cpp)

target_link_libraries(ep01_basic PUBLIC MathFunctions)

target_include_directories(ep01_basic
    PUBLIC
    "${CMAKE_CURRENT_BINARY_DIR}"  # 包含生成的配置头文件目录
    "${PROJECT_SOURCE_DIR}/MathFunctions"  # 包含MathFunctions的头文件目录
)





