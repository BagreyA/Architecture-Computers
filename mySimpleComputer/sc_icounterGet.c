//возвращает значение счетчика команд
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdio.h>

int
sc_icounterGet (int *value)
{
  if (value == NULL)
    return -1;

  *value = CX;

  return 0;
}