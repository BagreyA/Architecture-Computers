//производит очистку и перемещение курсора в левый верхний угол экрана
#include "../include/myTerm.h"
#include <unistd.h>

int
mt_clrscr (void)
{
  write (1, "\033[H\033[J", 7);
  return 0;
}