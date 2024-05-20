//устанавливает значение счетчика команд
#include "../include/mySimpleComputer.h"
#include "sc.h"

int
sc_icounterSet (int value)
{
  int max_value = MEMORY_SIZE - 1;
  int min_value = 0;

  if (value > max_value || value < min_value)
    return -1;

  CX = value;

  return 0;
}