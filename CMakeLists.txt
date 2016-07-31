cmake_minimum_required(VERSION 3.0)
project(libint LANGUAGES C CXX)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

################################### Modules ####################################
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(autocmake_safeguards)
include(Psi4Macros)

################################### Options ####################################
option_with_default(LIBINT_OPT_AM "Maximum angular momentum for integrals" 5)
option_with_print(BUILD_SHARED_LIBS "Build libint as shared library" OFF)
option_with_flags(ENABLE_XHOST "Enables processor-specific optimization" ON 
                  "-xHost" "-march=native")

################################# Main Project #################################
add_subdirectory(src)
configure_file("libintConfig.cmake.in" "libintConfig.cmake" @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/libintConfig.cmake 
        DESTINATION ${CMAKE_INSTALL_PREFIX})
