#Cmake 最低版本要求
cmake_minimum_required(VERSION 3.15)

#项目信息
project (MySTL)
# support c++14
set (CMAKE_CXX_STANDARD 14)

# 是否使用自己的代码库
OPTION(USE_TREE
        "use provided tree implementation" ON)

# 加入一个配置头文件，用于处理CMake对源码的设置
configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

# 是否加入base 库
if(USE_TREE)
    include_directories("${PROJECT_SOURCE_DIR}/Tree")
    add_subdirectory(Tree)
    set(EXTRA_LIBS ${EXTRA_LIBS} Tree)
endif(USE_TREE)
# 查找当前目录下的所有源文件,并保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

# 指定生产目标
add_executable(Demo ${DIR_SRCS})
# 指定链接库
target_link_libraries(Demo ${EXTRA_LIBS})


# 启用测试
enable_testing()

# 测试程序运行
add_test(test_run Demo 1 1)