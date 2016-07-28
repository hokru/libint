cmake_minimum_required(VERSION 3.0)
project(libint LANGUAGES C CXX)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
option(BUILD_SHARED_LIBS "Build libint library as shared object" OFF)

add_subdirectory(src)
configure_file("libintConfig.cmake.in" "libintConfig.cmake" @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/libintConfig.cmake 
        DESTINATION ${CMAKE_INSTALL_PREFIX})
