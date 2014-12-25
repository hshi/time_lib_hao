set(time_test_srcs time_hao_test.cpp test_all.cpp)

add_executable(timetest ${time_test_srcs})

target_link_libraries(timetest timehao)

install(TARGETS timetest  DESTINATION test)
