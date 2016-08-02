cmake_minimum_required(VERSION 3.0)
project(libint LANGUAGES C CXX)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

################################### Modules ####################################
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Psi4Macros)
include(autocmake_safeguards)
include(autocmake_static_library)

################################### Options ####################################
option_with_default(MAX_AM_ERI "Maximum angular momentum for integrals (min value 3)" 5)
option_with_print(BUILD_SHARED_LIBS "Build libint as shared library" OFF)
option_with_default(BUILD_FPIC "Libraries will be compiled with position independent code" ON)
if(${BUILD_SHARED_LIBS} AND NOT ${BUILD_FPIC})
    message(FATAL_ERROR "BUILD_SHARED_LIBS ON and BUILD_FPIC OFF are incompatible, as shared library requires position independent code")
endif()
option_with_print(ENABLE_GENERIC "Enable mostly static linking in shared library" OFF)
option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON
                    "-xHost" "-march=native")
# CODE_COVERAGE should be tested and probably propagated to external projects
#option_with_flags(ENABLE_CODE_COVERAGE "Enables details on code coverage" OFF
#                    "-ftest-coverage")

################################# Main Project #################################
add_subdirectory(src)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
configure_package_config_file(libintConfig.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/libintConfig.cmake"
                              INSTALL_DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/libint")
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/libintConfigVersion.cmake
                                 VERSION 1.1.6
                                 COMPATIBILITY SameMajorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libintConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/libintConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/libint)

