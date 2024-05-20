//устанавливает цвет фона последующих выводимых символов
#include "../include/myTerm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
mt_setfgcolor (enum colors color)
{
  char buf[10];
  sprintf (buf, "\033[3%dm", color);
  write (1, buf, strlen (buf));
  return 0;
}