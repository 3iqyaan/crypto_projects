cmake_minimum_required(VERSION 3.15)
project(CryptMathCLI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(crypt_math STATIC crypt_math.cpp crypt_math.hpp)

add_executable(cryptmath_cli libtest_cli.cpp)

target_link_libraries(cryptmath_cli PRIVATE crypt_math)

find_library(READLINE_LIB readline REQUIRED)
find_library(HISTORY_LIB history REQUIRED)

target_link_libraries(cryptmath_cli PRIVATE ${READLINE_LIB} ${HISTORY_LIB})

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}/*
    COMMENT "Cleaning all build files"
)
