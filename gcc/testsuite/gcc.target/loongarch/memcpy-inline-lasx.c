/* { dg-do compile } */
/* { dg-options "-O3 -mno-strict-align -mlasx" } */
/* { dg-final { scan-assembler "xvld" } } */

#include <string.h>

void mycpy(int *a, int *b) {
  memcpy(a, b, 256); 
}
