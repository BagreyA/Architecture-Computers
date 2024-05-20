//отображаем сообщение на экране консоли
#include <console.h>
#include <myTerm.h>
#include <stdio.h>

void
print_message (char *msg)
{
  mt_gotoXY (0, 30);
  printf ("%s", msg);
  gui_refresh_flag = 1;
}