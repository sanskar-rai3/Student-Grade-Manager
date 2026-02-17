cmake_minimum_required(VERSION 3.15)
project(Student_Grade_Manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(Student_Grade_Manager
    src/main.cpp
    src/student.cpp
)