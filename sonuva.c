#define SONUVA_IMPLEMENTATION
#include "sonuva.h"

int main()
{
  LOG("This is a Log");
  LOG("This is a Warning", "warn");
  LOG("This is a TODO", "todo");
  LOG("HELLO", "fatal");
  return 0;
}
