//устанавливает значение указанного регистра флагов. Если указан недопустимый
//регистр, то функция завершается со статусом -1 и значение флага не меняется.
//Иначе статус завершения – 0
#include "../include/mySimpleComputer.h"
#include "sc.h"

#define F_MASK(F) (1 << (F))

int
sc_regSet (int reg, int value)
{
  if (reg >= 5 || reg < 0)
    return -1;
  if (value == 0)
    {
      Flag = Flag & (~(F_MASK (reg)));
    }
  else
    {
      Flag = Flag | F_MASK (reg);
    }

  return 0;
}