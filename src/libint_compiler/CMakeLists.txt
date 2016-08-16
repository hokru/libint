cmake_minimum_required(VERSION 3.0)
project(libint_compiler LANGUAGES C)

# <<<  Build  >>>

set(COMPILER_SRC build_libint.c
                 emit_hrr_build.c
                 emit_hrr_build_macro.c
                 emit_order.c
                 emit_vrr_build.c
                 emit_vrr_build_macro.c
                 mem_man.c
                 constants.c
)
add_executable(libint_compiler ${COMPILER_SRC})
find_package(M REQUIRED)
target_link_libraries(libint_compiler ${LIBM_LIBRARIES})
set_target_properties(libint_compiler PROPERTIES COMPILE_FLAGS "-std=c99")

math(EXPR LIBINT_NEW_AM ${MAX_AM_ERI}*2)
target_compile_definitions(libint_compiler
    PRIVATE -DLIBINT_NEW_AM=${LIBINT_NEW_AM}
            -DLIBINT_OPT_AM=${MAX_AM_ERI}
            -DLIBINT_MAX_CLASS_SIZE=300
            -DLIBINT_LONG_DOUBLE=0)

# <<<  Install  >>>

install(TARGETS libint_compiler
        RUNTIME DESTINATION bin)
