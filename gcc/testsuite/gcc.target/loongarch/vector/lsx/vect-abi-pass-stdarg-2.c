/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d -mdouble-float" } */
/* { dg-final { scan-assembler "addi\\.w\t\\\$r8,\\\$r0,2" } } */
/* { dg-final { scan-assembler "vpickve2gr\\.du\t\\\$r6,\\\$vr1,0" } } */
/* { dg-final { scan-assembler "vpickve2gr\\.du\t\\\$r7,\\\$vr1,1" } } */

#include <lsxintrin.h>

extern void __attribute__ ((vecarg))
foo (float n, ...);

__m128i v;

void
bar ()
{
  foo (0, 1, v, 2);
}
