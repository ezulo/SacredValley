cmake_minimum_required(VERSION 3.7.2)
project (my_game)
ADD_LIBRARY(SFML
  /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
  /usr/lib/x86_64-linux-gnu/libsfml-window.so
  /usr/lib/x86_64-linux-gnu/libsfml-system.so
)
add_executable (my_game main.cpp)
target_link_libraries(my_game SFML)
