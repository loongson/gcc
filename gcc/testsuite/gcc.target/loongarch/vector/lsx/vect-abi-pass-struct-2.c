/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "vori\\.b\t\\\$vr0,\\\$vr1,0" } } */
/* { dg-final { scan-assembler "fmov\\.d\t\\\$f1,\\\$f2" } } */

#include <lsxintrin.h>

// Vector and scalar double member.
struct blk
{
  __m128i a;
  double b;
};

extern __attribute__ ((vecarg)) void bar (struct blk x);

__attribute__ ((vecarg)) void
foo (double x, struct blk y)
{
  bar (y);
}
