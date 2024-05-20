//выводит результат декодирования ячейки памяти, адрес которой указан в
//счетчике команд
#include "../include/mySimpleComputer.h"
#include "../include/myTerm.h"
#include <stdio.h>

void
printCommand (void)
{
  mt_gotoXY (95, 5);
  int cx = 0;
  sc_icounterGet (&cx);
  if (sc_commandValidate (cx) != 0)
    {
      printf ("! ");
    }
  int val = 0;
  if (sc_memoryGet (cx, &val))
    {
      return;
    }

  int sign = 0;
  int command = 0;
  int operand = 0;
  sc_commandDecode (val, &sign, &command, &operand);
  if (sign == 1)
    {
      printf ("- ");
    }
  else
    {
      printf ("+ ");
    }
  printf ("%02d : %02d", command, operand);
}