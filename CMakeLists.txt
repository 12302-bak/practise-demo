cmake_minimum_required(VERSION 3.10)

project(practise_demo C)
set(CMAKE_C_STANDARD 11)

# subdirectory
add_subdirectory(macosx_system_call)

# head file
include_directories(
        "${PROJECT_SOURCE_DIR}/external/cJson"
        "${PROJECT_SOURCE_DIR}/macosx_system_call/include"
)

# static _lib
#link_directories(${PROJECT_SOURCE_DIR}/external/cJson/static)
#link_libraries(cjson cjson_utils)

# shared _lib
link_directories(${PROJECT_SOURCE_DIR}/external/cJson/shared)


add_executable(app main.c)

target_link_libraries(app
        # install_name_tool -id ../external/cJson/shared/libcjson.dylib ../external/cJson/shared/libcjson.dylib
        # install_name_tool -id ../external/cJson/shared/libcjson_utils.dylib ../external/cJson/shared/libcjson_utils.dylib
        cjson cjson_utils
        proxy
)
