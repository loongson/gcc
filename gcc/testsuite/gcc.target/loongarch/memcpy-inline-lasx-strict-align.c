/* { dg-do compile } */
/* { dg-options "-O3 -mlasx -mstrict-align" } */
/* { dg-final { scan-assembler-not "xvld" } } */

#include <string.h>

void mycpy(int *a, int *b) {
  memcpy(a, b, 256); 
}
