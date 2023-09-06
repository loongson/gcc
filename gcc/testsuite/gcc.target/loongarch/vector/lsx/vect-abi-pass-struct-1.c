/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "vori\\.b\t\\\$vr0,\\\$vr1,0" } } */

#include <lsxintrin.h>

// Single vector inside struct
struct blk
{
  __m128i a;
};

extern __attribute__ ((vecarg)) void bar (struct blk x);

__attribute__ ((vecarg)) void
foo (double x, struct blk y)
{
  bar (y);
}
