#ifdef SONUVA_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define NARGS(...) NARGS_(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define NARGS_(_5, _4, _3, _2, _1, N, ...) N

#define LOGG(A, B) LOGG_(A, B)
#define LOGG_(A, B) A##B

#define LOG(...) LOGG(LOG, NARGS(__VA_ARGS__))(__VA_ARGS__)

void LOG1(char *str);
void LOG2(char *str, char* level);


void LOG1(char *str) { printf("\e[0;34m+ [INFO] \e[0m%s\n", str); }

void LOG2(char *str, char *level) {
  if (strcmp(level, "warn") == 0) {
    printf("\e[0;33m! [WARN] \e[0m%s\n", str);
    return;
  }

  if (strcmp(level, "fatal") == 0) {
    printf("\e[0;31m!! [FATAL] \e[0m%s\n", str);
    exit(1);
  }

  if (strcmp(level, "todo") == 0) {
    printf("+ [TODO] %s\n", str);
  }
}

// Vector


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


void vec_swap(Vector *v, int pos1, int pos2) {
  int temp = v->arr[pos1];
  v->arr[pos1] = v->arr[pos2];
  v->arr[pos2] = temp;
}


// Hashmap

typedef struct HashMapElem {
  char* key,
  char* value;
}

typedef struct HashMap {
  size_t size;
  size_t capacity;
  HashMapElem *arr;  
} HashMap;

void hs_put() {}

void hs_get() {}

void 



#endif // SONUVA_IMPLEMENTATION
