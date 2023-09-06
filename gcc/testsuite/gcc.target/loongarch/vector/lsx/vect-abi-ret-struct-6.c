/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "vld\t\\\$vr1,\\\$r3,48" } } */
/* { dg-final { scan-assembler "vld\t\\\$vr0,\\\$r3,32" } } */

#include <lsxintrin.h>

struct blk
{
  __m128i a;
  int empty0[0];
  int : 0;
  __m128i b;
} arg;

struct blk __attribute__ ((vecarg))
foo ()
{
  return arg;
}
