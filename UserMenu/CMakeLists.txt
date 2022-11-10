cmake_minimum_required(VERSION 3.21)
project(UserMenu)

set(CMAKE_CXX_STANDARD 20)

add_executable(UserMenu
        UserMain.cpp
        UserMenu.cpp)

target_link_libraries(UserMenu Dormitory)