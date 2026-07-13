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




#endif // SONUVA_IMPLEMENTATION
