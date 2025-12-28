modern_cpp_add_test(
  smoke_test
  smoke_test.cc
  ${CMAKE_SOURCE_DIR}/demos/warmup/week01/view01.cc
)
target_compile_definitions(smoke_test PRIVATE VIEW01_NO_MAIN)
target_include_directories(smoke_test PRIVATE ${CMAKE_SOURCE_DIR}/demos/warmup/week01)
target_link_libraries(smoke_test PRIVATE fmt::fmt)
