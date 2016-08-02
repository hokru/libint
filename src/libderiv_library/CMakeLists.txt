cmake_minimum_required(VERSION 3.0)
project(libderiv_library LANGUAGES C CXX)
include(GNUInstallDirs)

include_directories(${LIBINT_INCLUDE_DIR})
file(GLOB FULL_SRC "${CMAKE_BINARY_DIR}/*.cc")
file(GLOB FULL_HEAD "${CMAKE_BINARY_DIR}/*.h")
# STATIC/SHARED on below governed by BUILD_SHARED_LIBS
add_library(deriv ${FULL_SRC})
#target_link_libraries(deriv ${LIBC_INTERJECT})
set_target_properties(deriv PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC})
install(FILES ${CMAKE_BINARY_DIR}/libderiv.h
              ${CMAKE_BINARY_DIR}/d1hrr_header.h
              ${CMAKE_BINARY_DIR}/deriv_header.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/libint)
install(TARGETS deriv
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})
