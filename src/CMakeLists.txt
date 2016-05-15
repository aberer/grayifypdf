cmake_minimum_required (VERSION 3.5)
set(CMAKE_VERBOSE_MAKEFILE on)
project (FillPoles CXX)

add_library(libfillpoles fillpoles.cxx)

add_executable(fillpoles main.cxx)
add_executable(fillpolestest fillpolestest.cxx)

target_link_libraries(fillpoles libfillpoles)
target_link_libraries(fillpolestest libfillpoles)

target_compile_features(fillpoles PRIVATE cxx_range_for)
target_compile_features(fillpolestest PRIVATE cxx_range_for)
target_compile_features(libfillpoles PRIVATE cxx_range_for)
