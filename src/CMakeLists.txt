set(time_srcs time_hao.cpp)

add_library(timehao STATIC ${time_srcs})

install(TARGETS timehao  DESTINATION lib)
