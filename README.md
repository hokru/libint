# libint

### History

This is the Libint project (http://evaleev.github.io/libint/) by
Prof. Edward F. Valeev (@evaleev) with early roots by Prof. Justin T.
Fermann.

Libint1 has source available on sourceforge 
(https://sourceforge.net/projects/libint/files/v1-releases/) or as a branch on GitHub
(https://github.com/evaleev/libint/tree/v1) and, as distributed,
builds with `make`. Libint1 separates the build process for derivative integrals.

Libint2 has source available on github (https://github.com/evaleev/libint) and,
as distributed, builds with `make`. Libint2 integrates the build process for
derivative integrals.

### This Repository

Libint1 and Libderiv1 have been in the *ab initio* quantum chemistry package Psi4
(http://psicode.org/, https://github.com/psi4/psi4) since 2009. Internal to Psi4, it
has, since about 2014, built with `cmake`, as designed by @andysim.
@ryanmrichard has reworked the cmake build and extracted the
project until suitable for `ExternalProject_Add`. This repository is libint1
and libderiv1 source wrapped up nicely in CMake.

#### Version

Once again, this is Libint1, not Libint2. This codebase probably (in GitHub terminology) forked from upstream at 1.1.4. But, the only difference between 1.1.4 and 1.1.5 is in the make build system, which this codebase doesn't use. And, the only difference between 1.1.5 and 1.1.6 is three lines of string printing, which this codebase has incorporated. On those grounds, this repository is labeled 1.1.6, even with the latest upstream Libint1 release.

#### Building

```bash
cmake -H. -Bobjdir \
 -DLIBINT_OPT_AM=4
cd objdir && make
make install 
```
The primary CMake option is `MAX_AM_ERI` to control the maximum angular momentum for integrals. This is a Psi4 quantity slightly different from those used internally by Libint:

`MAX_AM_ERI` | `LIBINT_MAX_AM` | `LIBINT_OPT_AM` | `LIBDERIV_MAX_AM1` | `LIBDERIV_MAX_AM12`
------------ | --------------- | --------------- | ------------------ | -------------------
3 | 4 | 2 | 3 | 2
4 | 5 | 3 | 4 | 3
**5** | **6** | **3** | **5** | **4**
6 | 7 | 4 | 6 | 5
7 | 8 | 4 |
8 | 9 | 5 |

For orientation on an atom such as Neon, the default **5** gets you conventional cc-pV5Z for energies, cc-pVQZ for gradients, cc-pVTZ for frequencies and density-fitted cc-pVQZ for energies, cc-pVTZ for gradients, cc-pVDZ for frequencies.

The build is also responsive to 

* static/shared toggle `BUILD_SHARED_LIBS`
* the install location `CMAKE_INSTALL_PREFIX`
* of course, `CMAKE_C_COMPILER`, `CMAKE_CXX_COMPILER`, `CMAKE_C_FLAGS`, and `CMAKE_CXX_FLAGS`

See [CMakeLists.txt](CMakeLists.txt) for options details and additional options. All these build options should be passed as `cmake -DOPTION`.

#### Detecting

This project installs with `libintConfig.cmake` and `libintConfigVersion.cmake` files suitable for use with CMake [`find_package()`](https://cmake.org/cmake/help/v3.2/command/find_package.html) in `CONFIG` mode.

* `find_package(libint)` - find any libint libraries and headers
* `find_package(libint 1.1.6 EXACT CONFIG REQUIRED COMPONENTS shared 6)` - find libint exactly version 1.1.6 built with shared libraries and `MAX_AM_ERI` >= 6 or die trying

See [libintConfig.cmake.in](libintConfig.cmake.in) for details of how to detect the Config file and what CMake variables and targets are exported to your project.

#### Using

After `find_package(libint ...)`,

* test if package found with `if(${libint_FOUND})` or `if(TARGET libint::libint)`
* link to library (establishes dependency), including header and definitions configuration with `target_link_libraries(mytarget libint::libint)`
* include header files using `target_include_directories(mytarget PRIVATE $<TARGET_PROPERTY:libint::libint,INTERFACE_INCLUDE_DIRECTORIES>)`
* compile target applying `-DUSING_libint;-DMAX_AM_ERI=N` definition using `target_compile_definitions(mytarget PRIVATE $<TARGET_PROPERTY:libint::libint,INTERFACE_COMPILE_DEFINITIONS>)`
