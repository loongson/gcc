/* { dg-do compile } */
/* { dg-options "-O3 -mstrict-align" } */
/* { dg-final { scan-assembler "ld.bu" } } */

#include <string.h>

void mycpy(int *a, int *b) {
  memcpy(a, b, 256); 
}
