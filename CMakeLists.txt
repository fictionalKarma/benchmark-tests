cmake_minimum_required (VERSION 2.8.0)
project (Factori-Benchmark)

set(CMAKE_CXX_FLAGS "-Wall -Werror -g -std=c++11")
set(SRC_FILES event.cpp  formfeed.cpp  main.cpp)
add_executable(benchmark ${SRC_FILES})
