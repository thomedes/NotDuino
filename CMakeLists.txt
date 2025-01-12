cmake_minimum_required(VERSION 3.10)

# Set the project name
project(NotDuino LANGUAGES CXX)

include(CTest)
enable_testing()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Werror")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the library
add_library(
  ${PROJECT_NAME} STATIC src/NotDuino.cpp src/HardwareConsole.cpp
                         src/HardwareSerial.cpp src/Print.cpp src/Wire.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(tests)
