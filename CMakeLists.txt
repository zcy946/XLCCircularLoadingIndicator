cmake_minimum_required(VERSION 3.14)
project(XLCCircularLoadingIndicator)

# 查找库
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE)
endif()

# 收集源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCES)

# 收集头文件
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

set(CMAKE_AUTOMOC ON) # 启用自动MOC
set(CMAKE_AUTORCC ON) # 启用自动RCC
set(CMAKE_AUTOUIC ON) # 启用自动UIC

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt5::Core Qt5::Gui Qt5::Widgets
)