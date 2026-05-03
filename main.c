#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void LOG_INFO(char *str) { printf("+ [INFO] %s\n", str); }

void LOG_LEVEL(char *str, char *level) {
  if (strcmp(level, "warn") == 0) {
    printf("! [WARN] %s\n", str);
    return;
  }

  if (strcmp(level, "fatal") == 0) {
    printf("!! [FATAL] %s\n", str);
  }
}


int main()
{
  LOG_INFO("This is a Log");
  LOG_LEVEL("This is a Warning", "warn");
  /* LOG("HELLO"); */
  return 0;
}
