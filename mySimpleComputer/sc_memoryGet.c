//возвращает значение указанной ячейки памяти в value. Если адрес выходит за
//допустимые границы или передан неверный указатель на value, то функция
//завершается со статусом -1. В случае успешного выполнения функции она
//завершается со статусом 0
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdio.h>

int
sc_memoryGet (int address, int *value)
{
  if (address >= MEMORY_SIZE || address < 0)
    {
      return -1;
    }

  if (value == NULL)
    return -1;

  int tmp_addr = address;
  tmp_addr = tmp_addr / 10 * 10;
  int tmp_val = 0;
  sc_updateCache (address, tmp_addr, &tmp_val);

  *value = tmp_val;

  return 0;
}