cmake_minimum_required(VERSION 3.21)
project(Studying_Practice_3_sem_4_task)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Dormitory)
add_subdirectory(UserMenu)
add_subdirectory(AdminMenu)

target_link_libraries(UserMenu Dormitory)
target_link_libraries(AdminMenu Dormitory)