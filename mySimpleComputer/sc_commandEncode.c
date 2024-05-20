//кодирует значение ячейки в соответствии с форматом команды Simple Computer и
//с использованием в качестве значений полей полученные знак, номер команды и
//операнд и помещает результат в value
#include "../include/mySimpleComputer.h"
#include "sc.h"

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  int tmp = 0;
  if (sign == 1)
    tmp = 1 << 14;
  command = command << 7;
  tmp = tmp | command;
  tmp = tmp | operand;
  *value = tmp;

  return 0;
}