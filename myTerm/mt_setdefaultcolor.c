//устанавливает цвета символов и фона в значения по умолчанию
#include <stdio.h>
#include <unistd.h>

int
mt_setdefaultcolor ()
{
  fflush (stdout);
  write (1, "\033[0m", 4);
  return 0;
}
