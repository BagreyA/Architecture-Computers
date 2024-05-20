//устанавливает значение аккумулятора
#include "../include/mySimpleComputer.h"
#include "sc.h"

int
sc_accumulatorSet (int value)
{
  int max_value = (1 << 15) - 1;
  int min_value = -(1 << 15);

  if (value > max_value || value < min_value)
    return -1;

  AX = value;

  return 0;
}