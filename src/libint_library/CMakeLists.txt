cmake_minimum_required(VERSION 3.0)
project(libint_library LANGUAGES C CXX)

file(GLOB FULL_SRC "${CMAKE_BINARY_DIR}/*.cc" vrr_build.c)
file(GLOB FULL_HEAD "${CMAKE_BINARY_DIR}/*.h")
add_library(int STATIC ${FULL_SRC})
set_target_properties(int PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC})
include_directories(${CMAKE_BINARY_DIR})
install(FILES ${FULL_HEAD}  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/libint)
install(TARGETS int ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)