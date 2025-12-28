cmake_minimum_required(VERSION 3.19)
project(modern-cpp CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(MODERN_CPP_FETCH_FMT "Fetch fmt if not found" ON)
option(MODERN_CPP_FETCH_GTEST "Fetch GoogleTest if not found" ON)
option(MODERN_CPP_FETCH_BENCHMARK "Fetch Google Benchmark if not found" ON)
option(MODERN_CPP_ENABLE_SANITIZERS "Enable ASan/UBSan in supported compilers" OFF)

include(cmake/ModernCpp.cmake)
modern_cpp_setup_dependencies()

add_subdirectory(demos)
add_subdirectory(topics)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)
  enable_testing()
  add_subdirectory(tests)
endif()
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/benchmarks)
  add_subdirectory(benchmarks)
endif()
