/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "ldptr\\.w\t\\\$r4,\\\$r12,32" } } */
/* { dg-final { scan-assembler "xvld\t\\\$xr0,\\\$r12,0" } } */

#include <lasxintrin.h>

// Vector and scalar int member.
struct blk
{
  __m256i a;
  int b;
} arg;

struct blk __attribute__ ((vecarg))
foo ()
{
  return arg;
}
