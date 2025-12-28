modern_cpp_add_benchmark(
  smoke_bench
  smoke_bench.cc
  ${CMAKE_SOURCE_DIR}/demos/warmup/week01/view01.cc
)
target_compile_definitions(smoke_bench PRIVATE VIEW01_NO_MAIN)
target_include_directories(smoke_bench PRIVATE ${CMAKE_SOURCE_DIR}/demos/warmup/week01)
target_link_libraries(smoke_bench PRIVATE fmt::fmt)
