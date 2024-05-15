/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "or\t\\\$r4,\\\$r3,\\\$r0"  }  } */

#include <lasxintrin.h>

struct blk
{
  __m256i a;
  int b;
  int c;
  int d;
};

extern __attribute__ ((vecarg)) void bar (struct blk x);

__attribute__ ((vecarg)) void
foo (double x, struct blk y)
{
  bar (y);
}
