/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "fld\\.d\t\\\$f1,\\\$r3,48" } } */
/* { dg-final { scan-assembler "vld\t\\\$vr0,\\\$r3,32" } } */

#include <lsxintrin.h>

// Vector and scalar double member.
struct blk
{
  __m128i a;
  double b;
} arg;

struct blk __attribute__ ((vecarg))
foo ()
{
  return arg;
}
