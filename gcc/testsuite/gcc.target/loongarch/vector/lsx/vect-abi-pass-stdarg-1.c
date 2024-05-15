/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d -mdouble-float" } */
/* { dg-final { scan-assembler "vpickve2gr\\.du\t\\\$r6,\\\$vr0,0" } } */
/* { dg-final { scan-assembler "vpickve2gr\\.du\t\\\$r7,\\\$vr0,1" } } */

#include <lsxintrin.h>

extern void __attribute__ ((vecarg))
foo (int n, ...);

__m128i v;

void
bar ()
{
  foo (1, v);
}
