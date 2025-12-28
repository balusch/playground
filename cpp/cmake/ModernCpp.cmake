function(modern_cpp_apply_sanitizers target_name)
  if(NOT MODERN_CPP_ENABLE_SANITIZERS)
    return()
  endif()
  if(MSVC)
    target_compile_options(${target_name} PRIVATE /fsanitize=address)
    target_link_options(${target_name} PRIVATE /fsanitize=address)
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${target_name} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(${target_name} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
  endif()
endfunction()

function(modern_cpp_add_demo target_name)
  add_executable(${target_name} ${ARGN})
  target_compile_features(${target_name} PRIVATE cxx_std_23)
  if(MSVC)
    target_compile_options(${target_name} PRIVATE /W4 /permissive-)
  else()
    target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic)
  endif()
  modern_cpp_apply_sanitizers(${target_name})
endfunction()

function(modern_cpp_add_test target_name)
  add_executable(${target_name} ${ARGN})
  target_compile_features(${target_name} PRIVATE cxx_std_23)
  modern_cpp_apply_sanitizers(${target_name})
  if(TARGET GTest::gtest_main)
    target_link_libraries(${target_name} PRIVATE GTest::gtest_main)
  elseif(TARGET gtest_main)
    target_link_libraries(${target_name} PRIVATE gtest_main)
  endif()
  add_test(NAME ${target_name} COMMAND ${target_name})
endfunction()

function(modern_cpp_add_benchmark target_name)
  add_executable(${target_name} ${ARGN})
  target_compile_features(${target_name} PRIVATE cxx_std_23)
  modern_cpp_apply_sanitizers(${target_name})
  if(TARGET benchmark::benchmark_main)
    target_link_libraries(${target_name} PRIVATE benchmark::benchmark_main)
  elseif(TARGET benchmark_main)
    target_link_libraries(${target_name} PRIVATE benchmark_main)
  endif()
endfunction()

function(modern_cpp_setup_dependencies)
  find_package(fmt CONFIG QUIET)
  if(NOT fmt_FOUND AND MODERN_CPP_FETCH_FMT)
    include(FetchContent)
    FetchContent_Declare(
      fmt
      GIT_REPOSITORY https://github.com/fmtlib/fmt.git
      GIT_TAG 10.2.1
    )
    FetchContent_MakeAvailable(fmt)
  endif()

  find_package(GTest CONFIG QUIET)
  if(NOT GTest_FOUND AND MODERN_CPP_FETCH_GTEST)
    include(FetchContent)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG release-1.14.0
    )
    FetchContent_MakeAvailable(googletest)
  endif()

  find_package(benchmark CONFIG QUIET)
  if(NOT benchmark_FOUND AND MODERN_CPP_FETCH_BENCHMARK)
    include(FetchContent)
    set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(
      benchmark
      GIT_REPOSITORY https://github.com/google/benchmark.git
      GIT_TAG v1.8.4
    )
    FetchContent_MakeAvailable(benchmark)
  endif()
endfunction()
