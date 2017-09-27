cmake_minimum_required(VERSION 3.7.2)
project (my_game)
set(SMFL /usr/lib/x86_64-linux-gnu)
include_directories(src)
add_executable (my_game src/main.cpp)
target_link_libraries(my_game 
  ${SMFL}/libsfml-graphics.so 
  ${SMFL}/libsfml-window.so
  ${SMFL}/libsfml-system.so
)
