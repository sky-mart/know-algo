file(GLOB ALGO_TESTS_SOURCES "*.cc")

add_executable(know-algo-tests ${ALGO_TESTS_SOURCES})
add_dependencies(know-algo-tests test-libs)
target_link_libraries(know-algo-tests
		know-algo
        gtest
        gtest_main
        )