//определяет размер экрана терминала
#include <sys/ioctl.h>

int
mt_getscreensize (int *rows, int *cols)
{
  struct winsize ws;
  if (ioctl (1, TIOCGWINSZ, &ws) != -1)
    {
      *rows = ws.ws_row;
      *cols = ws.ws_col;
      return 0;
    }
  return -1; // Ошибка при определении размеров экрана
}