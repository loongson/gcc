/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "vori\\.b\t\\\$vr0,\\\$vr1,0" } } */
/* { dg-final { scan-assembler "vori\\.b\t\\\$vr1,\\\$vr2,0" } } */

#include <lsxintrin.h>

struct blk
{
  __m128i a;
  __m128i b;
};

extern __attribute__ ((vecarg)) void bar (struct blk x);

__attribute__ ((vecarg)) void
foo (double x, struct blk y)
{
  bar (y);
}
