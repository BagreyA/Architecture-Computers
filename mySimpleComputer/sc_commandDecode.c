//декодирует значение ячейки памяти как команду Simple Computer
#include "../include/mySimpleComputer.h"
#include "sc.h"

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  *sign = (value >> 14) & 0x1;
  *command = (value >> 7) & 0x7F;
  *operand = value & 0x7F;
  return 0;
}