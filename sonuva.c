#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SONUVA_IMPLEMENTATION
#include "sonuva.h"

typedef struct Vector {
  size_t size;
  size_t capacity;
  int *arr;  
} Vector;

void vec_push(Vector *v, int value) {
  if (v) {
    if (v->size >= v->capacity) {
      size_t new_capacity = v->capacity * 2;
      if(new_capacity == 0) new_capacity = 8;
      int *bigger_arr = realloc(v->arr, (sizeof(int) * new_capacity));
      v->arr = bigger_arr;
      v->capacity = new_capacity;
    }
  } else {
    v = malloc(sizeof(Vector) * 2);
    v->capacity = sizeof(Vector) * 2;
    v->size = 0;
  }
  v->arr[v->size] = value;
  v->size++;
}

int main() {
  Vector *v = malloc(sizeof(Vector));
  vec_push(v, 10);
  vec_push(v, 20);
  for (int i =0; i< v->capacity; i++) {
    printf("%d\n", v->arr[i]);
  }
  /* vec_rem(v, 10); */
  /* vec_delete(v, 10); */
  /* vec_purge(v, 10); */
  /* vec_swap(v, 1, 2); */



  LOG("This is a Log");
  LOG("This is a Warning", "warn");
  LOG("This is a TODO", "todo");
  LOG("This is a Fatal", "fatal");
  return 0;
}
