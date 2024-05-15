/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d -Wno-strict-aliasing" } */
/* { dg-final { scan-assembler "xvori\\.b\t\\\$xr0,\\\$xr1,0" } } */

#include <lasxintrin.h>

// Single vector inside struct
struct blk
{
  __m256i a;
};

struct blk __attribute__ ((vecarg))
foo (double, struct blk arg)
{
  return arg;
}
