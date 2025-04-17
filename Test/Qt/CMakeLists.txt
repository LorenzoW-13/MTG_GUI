cmake_minimum_required(VERSION 3.16)

project(Test VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/home/lw13/Qt/6.8.2/gcc_64")

set(Qt6_DIR "/home/lw13/Qt/6.8.2/gcc_64/lib/cmake/Qt6")
set(Qt6Widgets_DIR "/home/lw13/Qt/6.8.2/gcc_64/lib/cmake/Qt6Widgets")

find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL)
qt_standard_project_setup()

qt_add_executable(Test
    test.cpp
    mainwindow.cpp
    mainwindow.ui
)

target_link_libraries(Test PRIVATE Qt6::Widgets)

set_target_properties(Test PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)