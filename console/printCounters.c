//выводит значение счетчика команд в нужном месте экрана (блок «Счетчик
//команд») и в соответствующем формате
#include "../include/mySimpleComputer.h"
#include <stdio.h>

void
printCounters (void)
{
  mt_gotoXY (68, 5);
  int CX = 0;
  sc_icounterGet (&CX);
  printf ("T: %04d IC: %04x", CX, CX);
}