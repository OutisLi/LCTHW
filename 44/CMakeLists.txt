# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(test)

# 设置C标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# 添加编译器警告标志和调试信息
add_compile_options(-Wall -g)

# 自动查找当前目录下所有的.c文件，并将文件列表存储在变量SRC_FILES中
file(GLOB SRC_FILES "*.c")

# # 自动查找src目录下所有的.c文件，并将文件列表存储在变量SRC_FILES中
# file(GLOB SRC_FILES "src/*.c")

# # 指定头文件的搜索路径，以便编译器可以找到include目录下的头文件
# include_directories(include)

# 定义目标可执行文件和自动收集到的源文件
add_executable(${PROJECT_NAME} ${SRC_FILES})