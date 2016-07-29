# libint

This is the Libint project (http://evaleev.github.io/libint/) by
Prof. Edward F. Valeev (@evaleev) with early roots by Prof. Justin T.
Fermann.

Libint1 has source available on sourceforge 
(https://sourceforge.net/projects/libint/files/v1-releases/) and, as distributed,
builds with `make`. Libint1 separates the build process for derivative integrals.

Libint2 has source available on github (https://github.com/evaleev/libint) and,
as distributed, builds with `make`. Libint2 integrates the build process for
derivative integrals.

### this repository

Libint1 and Libderiv1 have been in the *ab initio* quantum chemistry package Psi4
(http://psicode.org/, https://github.com/psi4/psi4) since 2009. Internal to Psi4, it
has, since about 2014, built with `cmake`, as designed by @andysim.
@ryanmrichard has reworked and standardized the cmake build and extracted the
project until suitable for `ExternalProject_Add`. This repository is libint1
source wrapped up nicely in CMake. See https://github.com/loriab/libderiv1
for the accompanying derivative integrals repository.

