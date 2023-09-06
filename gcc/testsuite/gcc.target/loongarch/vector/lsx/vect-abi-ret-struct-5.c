/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d" } */
/* { dg-final { scan-assembler "vst\t\\\$vr0,\\\$r4,0"  }  } */
/* { dg-final { scan-assembler "vst\t\\\$vr0,\\\$r4,16"  }  } */

#include <lsxintrin.h>

struct blk
{
  __m128i a;
  int b;
  int c;
  int d;
} arg;

struct blk __attribute__ ((vecarg))
foo ()
{
  return arg;
}
