/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "vori\\.b\t\\\$vr0,\\\$vr1,0" } } */

#include <lsxintrin.h>

// Single vector inside struct
struct blk
{
  __m128i a;
};

struct blk __attribute__ ((vecarg))
foo (double, struct blk arg)
{
  return arg;
}
