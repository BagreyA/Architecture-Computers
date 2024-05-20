//задает значение указанной ячейки памяти как value. Если адрес выходит за
//допустимые границы или value не соответствует допустимому диапазону значений,
//то функция возвращает -1, иначе завершается корректно и возвращает 0
#include <stdlib.h>

#include "../include/mySimpleComputer.h"
#include "sc.h"

int
sc_memorySet (int address, int value)
{
  if (address >= MEMORY_SIZE || address < 0)
    {
      return -1;
    }
  int max_value = (1 << 15) - 1;
  int min_value = -(1 << 15);
  if (value < min_value || value > max_value)
    {
      return -1;
    }

  int tmp_addr = address;
  tmp_addr = tmp_addr / 10 * 10;
  int tmp_val = 0;
  sc_updateCache (address, tmp_addr, &tmp_val);
  memory[address] = value;
  return 0;
}