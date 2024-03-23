cmake_minimum_required(VERSION 3.23)
project(k_lang)

set(CMAKE_CXX_STANDARD 23)

add_executable(k_lang src/main.cpp src/Token/TokenName.h src/Scanner.cpp src/Scanner.h src/Token/Token.cpp src/Token/Token.h src/Token/IdToken.cpp src/Token/IdToken.h src/Token/StringToken.cpp src/Token/StringToken.h src/Token/NumberToken.cpp src/Token/NumberToken.h)
