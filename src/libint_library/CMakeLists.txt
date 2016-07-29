cmake_minimum_required(VERSION 3.0)
project(libint_library LANGUAGES C CXX)
include(GNUInstallDirs)

file(GLOB FULL_SRC "${CMAKE_BINARY_DIR}/*.cc" vrr_build.c)
file(GLOB FULL_HEAD "${CMAKE_BINARY_DIR}/*.h")
# STATIC/SHARED on below governed by BUILD_SHARED_LIBS
add_library(int ${FULL_SRC})
target_link_libraries(int ${LIBC_INTERJECT})
set_target_properties(int PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC})
include_directories(${CMAKE_BINARY_DIR})
install(FILES ${CMAKE_BINARY_DIR}/libint.h DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/libint)
install(TARGETS int ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
                    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})
