/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d -mdouble-float" } */
/* { dg-final { scan-assembler "vpickve2gr\\.du\t\\\$r4,\\\$vr0,0" } } */
/* { dg-final { scan-assembler "vpickve2gr\\.du\t\\\$r5,\\\$vr0,1" } } */

#include <lsxintrin.h>

extern void __attribute__ ((vecarg))
bar (float, float, float, float, float, float, float, float, __m128i v);

__m128i v;

void
foo ()
{
  bar (0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, v);
}
