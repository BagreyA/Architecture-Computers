//перемещает курсор в указанную позицию.
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
mt_gotoXY (int x, int y)
{
  char buf[15];
  sprintf (buf, "\033[%d;%dH", y, x);
  write (1, buf, strlen (buf));
  return 0;
}