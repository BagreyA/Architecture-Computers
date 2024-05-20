#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdio.h>
#define F_GET(K) ((Flag >> (K)) & 0x1)

int
sc_regGet (int reg, int *value)
{
  if (reg >= 5 || reg < 0)
    return -1;
  if (value == NULL)
    return -1;

  *value = F_GET (reg);

  return 0;
}