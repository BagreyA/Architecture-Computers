// скрывает или показывает курсор
#include <unistd.h>

int
mt_setcursorvisible (int value)
{
  if (value)
    {
      write (1, "\033[?25h", 6);
    }
  else
    {
      write (1, "\033[?25l", 6);
    }
  return 0;
}