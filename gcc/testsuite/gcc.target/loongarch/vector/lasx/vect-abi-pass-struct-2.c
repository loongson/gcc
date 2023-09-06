/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "xvori\\.b\t\\\$xr0,\\\$xr1,0" } } */
/* { dg-final { scan-assembler "fmov\\.d\t\\\$f1,\\\$f2" } } */

#include <lasxintrin.h>

// Vector and scalar double member.
struct blk
{
  __m256i a;
  double b;
};

extern __attribute__ ((vecarg)) void bar (struct blk x);

__attribute__ ((vecarg)) void
foo (double x, struct blk y)
{
  bar (y);
}
