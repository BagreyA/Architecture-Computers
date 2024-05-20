//инициализирует регистр флагов значениями по умолчанию
#include "../include/mySimpleComputer.h"
#include "sc.h"

int
sc_regInit (void)
{
  AX = 0;
  CX = 0;
  Flag = 0;

  sc_regSet (IGNORE_SIGNAL_FLAG, 1);

  return 0;
}