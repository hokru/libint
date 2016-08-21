/*! \file
    \ingroup INT
    \brief Enter brief description of file here
*/

#ifndef _psi3_src_lib_libint_constants_h_
#define _psi3_src_lib_libint_constants_h_

  extern int io[31];
  extern const char am_letter[48];
  extern const char *number[31];

  /*----------------------------------------------------------------------------------
    hash(a,b) returns a number of the (a[0] a[1]) type product within a doublet.
    a contains x y and z exponents of functions on centers A and B, and b contains
    their angular momenta
   ----------------------------------------------------------------------------------*/
  int hash(int a[2][3],int b[2]);



#endif