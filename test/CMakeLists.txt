set(test_exe timetest)

file(GLOB test_srcs "*.cpp")

add_executable(${test_exe} ${test_srcs})

target_link_libraries(${test_exe} timehao)

install(TARGETS ${test_exe}  DESTINATION test)
