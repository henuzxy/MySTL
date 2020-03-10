#Cmake 最低版本要求
cmake_minimum_required(VERSION 3.15)

#项目信息
project (MySTL)
# support c++11
set (CMAKE_CXX_STANDARD 14)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加子目录
add_subdirectory(Base)
#指定生产目标
add_executable(Demo main.cpp)

