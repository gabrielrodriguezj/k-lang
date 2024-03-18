cmake_minimum_required(VERSION 3.23)
project(k_lang)

set(CMAKE_CXX_STANDARD 23)

add_executable(k_lang src/main.cpp src/Token/NombreToken.cpp)
