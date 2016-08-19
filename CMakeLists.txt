cmake_minimum_required(VERSION 3.0)
project(libint LANGUAGES C CXX)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

################################### Options ####################################
include(Psi4Macros)
option_with_default(CMAKE_BUILD_TYPE "Build type" Release)
option_with_default(MAX_AM_ERI "Maximum angular momentum for integrals (min value 3)" 5)
option_with_print(BUILD_SHARED_LIBS "Build final library as shared, not static" OFF)
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

######################### Process & Validate Options ###########################
include(autocmake_safeguards)
include(autocmake_static_library)

################################# Main Project #################################
add_subdirectory(src)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(PN ${PROJECT_NAME})

# <<<  Install  >>>

install(DIRECTORY ${CMAKE_BINARY_DIR}/stage/${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
                  ${CMAKE_BINARY_DIR}/stage/${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}
                  ${CMAKE_BINARY_DIR}/stage/${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        USE_SOURCE_PERMISSIONS
        PATTERN "*header*" EXCLUDE)

# <<<  Export Config  >>>

set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_DATADIR}/cmake/${PN}")
configure_package_config_file(${PN}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake"
                              INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR})
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
                                 VERSION 1.1.6
                                 COMPATIBILITY SameMajorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})
