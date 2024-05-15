/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "xvori\\.b\t\\\$xr0,\\\$xr1,0" } } */

#include <lasxintrin.h>

// Vector and scalar int member.
struct blk
{
  __m256i a;
  int b;
};

extern __attribute__ ((vecarg)) void bar (struct blk x);

__attribute__ ((vecarg)) void
foo (double x, struct blk y)
{
  bar (y);
}
