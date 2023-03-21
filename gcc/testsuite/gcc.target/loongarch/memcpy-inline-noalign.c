/* { dg-do compile } */
/* { dg-options "-O3" } */
/* { dg-final { scan-assembler-not "ld.bu" } } */

#include <string.h>

void mycpy(int *a, int *b) {
  memcpy(a, b, 256); 
}
