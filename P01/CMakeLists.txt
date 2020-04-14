cmake_minimum_required(VERSION 3.15)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)


# 项目属相设置
project(P1)
set(CMAKE_C_STANDARD 99)
include_directories(include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置共享库输出文件
add_library(movies STATIC src/MovieList/movies.c)
add_library(movies_shared SHARED src/MovieList/movies.c)
set_target_properties(movies_shared PROPERTIES OUTPUT_NAME "movies")

# 设置main输出文件。
# 会生成${PROJECT_NAME}.exe
add_executable(${PROJECT_NAME} main.c)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} movies)

# 多线程相关输出测试
# 会生成${PROJECT_NAME}_mutex.exe,${PROJECT_NAME}_semphore.exe,${PROJECT_NAME}_multiThreadDebug.exe
add_executable(${PROJECT_NAME}_mutex mainTestMutex.c)
add_executable(${PROJECT_NAME}_semphore mainTestSemphere.c)
add_executable(${PROJECT_NAME}_multiThreadDebug mainPthreadDebug.c)

# EasyXa使用案例输出文件测试。
# 注意用cygwin编译，会把目录linux化
#include_directories(/cygdrive/d/zhuxiaobing/VS2019/EasyX/Include)
#link_directories(/cygdrive/d/zhuxiaobing/VS2019/EasyX/lib/VC2017/x86)
# 注意用vs编译器，目录要用如下这种。
include_directories(D:\\zhuxiaobing\\VS2019\\EasyX\\Include)
link_directories(D:\\zhuxiaobing\\VS2019\\EasyX\\lib\\VC2017\\x86)
link_libraries(EasyXa)
add_executable(${PROJECT_NAME}_graphics mainTestGraphics.cpp)
target_link_libraries(${PROJECT_NAME}_graphics EasyXa)

# install
set(CMAKE_INSTALL_PREFIX /cygdrive/d/WorkCode/happyC/P01)
message(${CMAKE_INSTALL_PREFIX})
install(TARGETS movies ARCHIVE DESTINATION lib2)
install(FILES include/movies.h DESTINATION include2)