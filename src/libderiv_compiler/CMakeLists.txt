cmake_minimum_required(VERSION 3.0)
project(libderiv_compiler LANGUAGES C)

# <<<  Build  >>>

set(COMPILER_SRC build_libderiv.c
                 emit_d1hrr_build_macro.c
                 emit_deriv1_managers.c
                 emit_deriv_build_macro.c
                 emit_d1hrr_build.c
                 emit_deriv12_managers.c
                 emit_deriv_build.c
                 mem_man.c
)
add_executable(libderiv_compiler ${COMPILER_SRC})

math(EXPR LIBDERIV_OPT_AM1 ${MAX_AM_ERI}-1)  # A.M. level for 1st derivative ERIs
math(EXPR LIBDERIV_OPT_AM2 ${MAX_AM_ERI}-2)  # A.M. level for 2nd derivative ERIs
math(EXPR LIBDERIV_NEW_AM1 ${LIBDERIV_OPT_AM1}*2)
math(EXPR LIBDERIV_NEW_AM2 ${LIBDERIV_OPT_AM2}*2)
math(EXPR LIBDERIV_NEW_AM12 ${LIBDERIV_OPT_AM2}*2)
target_compile_definitions(libderiv_compiler
    PRIVATE -DLIBDERIV_NEW_AM1=${LIBDERIV_NEW_AM1}
            -DLIBDERIV_NEW_AM2=${LIBDERIV_NEW_AM2}
            -DLIBDERIV_NEW_AM12=${LIBDERIV_NEW_AM2})

    # acquire libint.h
find_package(libintint CONFIG REQUIRED)
target_include_directories(libderiv_compiler PRIVATE
    $<TARGET_PROPERTY:libint::int,INTERFACE_INCLUDE_DIRECTORIES>)

# <<<  Install  >>>

install(TARGETS libderiv_compiler
        RUNTIME DESTINATION bin)
