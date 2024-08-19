
**note**

```shell
# 链接CoreFoundation框架
# target_link_libraries(${PROJECT_NAME} "-framework CoreFoundation" "-framework SystemConfiguration")
#[[target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/external/cJson"
)

option(USE_STATIC "use static _lib" ON)

if(USE_STATIC)
    target_link_libraries(${PROJECT_NAME}
            ${PROJECT_SOURCE_DIR}/external/cJson/static/libcjson.a
            ${PROJECT_SOURCE_DIR}/external/cJson/static/libcjson_utils.a
    )
else ()
    # export DYLD_LIBRARY_PATH=/Users/stevenobelia/Documents/project_clion_test/practise-demo/external/cJson/shared:$DYLD_LIBRARY_PATH
    target_link_libraries(${PROJECT_NAME}
            ${PROJECT_SOURCE_DIR}/external/cJson/shared/libcjson.dylib
            ${PROJECT_SOURCE_DIR}/external/cJson/shared/libcjson_utils.dylib
    )
endif()]]






# install_name_tool -id libhello.dylib libhello.dylib
# install_name_tool 需要注意路径
# rpath
# linux
#   patchelf --set-soname libhello.so ../external/cJson/shared/libhello.so
#   readelf -d ../external/cJson/shared/libhello.so
```