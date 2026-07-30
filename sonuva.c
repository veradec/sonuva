#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SONUVA_IMPLEMENTATION
#include "sonuva.h"


int main() {
  Vector *v = malloc(sizeof(Vector));
  vec_push(v, 10);
  vec_push(v, 20);
  vec_swap(v, 0, 1);
  LOG("Values in Vector");
  for (int i =0; i< v->size; i++) {
    printf("%d : %d\n", i, v->arr[i]);
  }
  printf("\n");

  LOG("Vector Remove", "todo");
  /* vec_rem(v, 10); */

  LOG("Vector Delete", "todo");
  /* vec_delete(v, 10); */

  LOG("Vector purge", "todo");
  /* vec_purge(v, 10); */

  


  printf("\n\n\033[31;1;4mTypes of Logs:");
  printf("\n");
  LOG("This is a Log");
  LOG("This is a Warning", "warn");
  LOG("This is a TODO", "todo");
  LOG("This is a Fatal", "fatal");
  return 0;
}
