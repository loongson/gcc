/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "ldptr\\.w\t\\\$r4,\\\$r3,48" } } */
/* { dg-final { scan-assembler "vld\t\\\$vr0,\\\$r3,32" } } */

#include <lsxintrin.h>

// Vector and scalar int member.
struct blk
{
  __m128i a;
  int b;
} arg;

struct blk __attribute__ ((vecarg))
foo ()
{
  return arg;
}
