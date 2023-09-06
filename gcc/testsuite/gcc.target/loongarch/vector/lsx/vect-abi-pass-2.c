/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d -mdouble-float" } */
/* { dg-final { scan-assembler "vld\t\\\$vr8,\\\$r12,0" } } */
/* { dg-final { scan-assembler "vst\t\\\$vr8,\\\$r3,0" } } */

#include <lsxintrin.h>

extern void __attribute__ ((vecarg))
bar (float, float, float, float, float, float, float, float, 
     int, int, int, int, int, int, int, __m128i v);

__m128i v;

void
foo ()
{
  bar (0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
       0, 0, 0, 0, 0, 0, 0, v);
}
