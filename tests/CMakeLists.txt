add_executable(core_tests core_tests.cpp)

target_link_libraries(core_tests PRIVATE core gtest_main)
