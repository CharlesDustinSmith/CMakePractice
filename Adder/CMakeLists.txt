add_library(adder adder.cpp)

install(TARGETS adder DESTINATION lib)
install(FILES adder.h DESTINATION include)