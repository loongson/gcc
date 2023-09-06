/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "xvld\t\\\$xr1,\\\$r12,32" } } */
/* { dg-final { scan-assembler "xvld\t\\\$xr0,\\\$r12,0" } } */

#include <lasxintrin.h>

struct blk
{
  __m256i a;
  int empty0[0];
  int : 0;
  __m256i b;
} arg;

struct blk __attribute__ ((vecarg))
foo ()
{
  return arg;
}
