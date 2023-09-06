/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "vld\t\\\$vr1,\\\$r3,80" } } */
/* { dg-final { scan-assembler "vld\t\\\$vr0,\\\$r3,64" } } */

#include <lsxintrin.h>

struct blk
{
  __m128i a;
  __m128i b;
};

struct blk __attribute__ ((vecarg))
foo (struct blk arg)
{
  return arg;
}
