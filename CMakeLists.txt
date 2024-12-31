cmake_minimum_required(VERSION 3.10)

# 项目名称和语言
project(infrared LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/demo/linux
    /usr/include/x86_64-linux-gnu
)

# 链接库文件目录
link_directories(
    ${CMAKE_SOURCE_DIR}/library/linux64
)

set(OUTPUT Infrared)

set(SOURCES
    demo/linux/DeviceBase.cpp
    demo/linux/GetStream.cpp
    demo/linux/Thermal.cpp
    demo/linux/main.cpp
)

add_executable(${OUTPUT} ${SOURCES})

target_link_libraries(${OUTPUT}
    HCUSBSDK
    pthread
)

add_custom_command(TARGET ${OUTPUT} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${OUTPUT}> ${CMAKE_SOURCE_DIR}/library/linux64
    COMMENT "Moving ${OUTPUT} to library/linux64"
)
