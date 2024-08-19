cmake_minimum_required(VERSION 2.8.0)

project(CALC C)
set(CMAKE_VERBOSE_MAKEFILE ON)



include_directories(${PROJECT_SOURCE_DIR}/include)






# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/_lib)
# add_library(calc STATIC ${SRC_LIST})
link_directories(${PROJECT_SOURCE_DIR}/external/cJson/shared)
add_executable(app main.c)

# install_name_tool -id libhello.dylib libhello.dylib
# install_name_tool 需要注意路径
# rpath
# linux
#   patchelf --set-soname libhello.so ../external/cJson/shared/libhello.so
#   readelf -d ../external/cJson/shared/libhello.so
target_link_libraries(app hello)