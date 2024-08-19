cmake_minimum_required(VERSION 3.10)
project(MSC C)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(proxy SHARED src/proxy.c)

target_link_libraries(proxy
        "-framework CoreFoundation" "-framework SystemConfiguration"
)


