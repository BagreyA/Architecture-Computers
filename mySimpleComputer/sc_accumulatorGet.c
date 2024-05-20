//возвращает значение аккумулятора
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdio.h>

int
sc_accumulatorGet (int *value)
{
  if (value == NULL)
    return -1;

  *value = AX;

  return 0;
}