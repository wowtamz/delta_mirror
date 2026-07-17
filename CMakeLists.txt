cmake_minimum_required(VERSION 3.20)

project(MyApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(MyApp
    src/main.cpp
)

target_link_libraries(MyApp PRIVATE ${wxWidgets_LIBRARIES})