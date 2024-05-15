/* { dg-do compile } */
/* { dg-options "-O2 -mvecarg -mabi=lp64d -Wno-strict-aliasing" } */

typedef double __m256d __attribute__ ((__vector_size__ (32),
				       __may_alias__));

typedef struct {
  __m256d x, y, z;
} __m256dx3;

__m256dx3
foo(__m256d x, __m256d y, __m256d z)
{
  __m256dx3 v = { x, y, z };
  return v;
}
