#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define NARGS(...) NARGS_(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define NARGS_(_5, _4, _3, _2, _1, N, ...) N

#define LOGG(A, B) LOGG_(A, B)
#define LOGG_(A, B) A##B

#define LOG(...) LOGG(LOG, NARGS(__VA_ARGS__))(__VA_ARGS__)


void LOG1(char *str) { printf("+ [INFO] %s\n", str); }

void LOG2(char *str, char *level) {
  if (strcmp(level, "warn") == 0) {
    printf("! [WARN] %s\n", str);
    return;
  }

  if (strcmp(level, "fatal") == 0) {
    printf("!! [FATAL] %s\n", str);
    exit(1);
  }
}


int main()
{
  LOG("This is a Log");
  LOG("This is a Warning", "warn");
  LOG("HELLO", "fatal");
  return 0;
}
