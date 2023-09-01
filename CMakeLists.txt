cmake_minimum_required(VERSION 3.26)
project(ModPow)

set(CMAKE_CXX_STANDARD 17)

set(SAFE_HERON_INCLUDE /usr/local/include/safeheron)
set(PB_INCLUDE /usr/local/include)

add_executable(${PROJECT_NAME} main.cpp)

find_library(SUITES_LIB NAMES SafeheronCryptoSuites PATHS /usr/local/lib/ REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SUITES_LIB})
target_include_directories(${PROJECT_NAME} PUBLIC ${SAFE_HERON_INCLUDE} ${PB_INCLUDE})