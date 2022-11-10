cmake_minimum_required(VERSION 3.21)
project(AdminMenu)

set(CMAKE_CXX_STANDARD 20)

add_executable(AdminMenu
        AdminMain.cpp
        AdminMenu.cpp)

target_link_libraries(AdminMenu Dormitory)
