//выводит значение в нужном месте экрана (блок «Аккумулятор»)
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdio.h>

void
printAccumulator (void)
{
  mt_gotoXY (66, 2);
  printf ("sc: %04d hex: %04x", AX, AX);
}