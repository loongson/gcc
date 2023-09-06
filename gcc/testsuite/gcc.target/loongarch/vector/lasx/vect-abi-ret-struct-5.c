/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "xvst\t\\\$xr0,\\\$r4,0"  }  } */
/* { dg-final { scan-assembler "xvst\t\\\$xr0,\\\$r4,32"  }  } */

#include <lasxintrin.h>

struct blk
{
  __m256i a;
  int b;
  int c;
  int d;
} arg;

struct blk __attribute__ ((vecarg))
foo ()
{
  return arg;
}
