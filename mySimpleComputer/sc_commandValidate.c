//проверяет значение поля «команда» на корректность
#include "../include/mySimpleComputer.h"
#include "sc.h"

int
sc_commandValidate (int command)
{
  if (command == 0 || command == 1)
    return 0;
  if (command == 10 || command == 11)
    return 0;
  if (command == 20 || command == 21)
    return 0;
  if (command >= 30 && command <= 33)
    return 0;
  if (command >= 40 && command <= 43)
    return 0;
  if (command >= 51 && command <= 76)
    return 0;

  return 1;
}