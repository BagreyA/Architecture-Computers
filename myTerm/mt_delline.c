//очищает текущую строку
#include "../include/myTerm.h"
#include <unistd.h>

int
mt_delline ()
{
  write (1, "\033[M", 3);
  return 0;
}