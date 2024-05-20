//проверка и корректировки значения переменной
#include <console.h>
#include <mySimpleComputer.h>

void
validate_cell (void)
{
  editing_cell = editing_cell < 0 ? 0 : editing_cell; //нижняя граница
  editing_cell = editing_cell > (MEMORY_SIZE - 1)
                     ? MEMORY_SIZE - 1
                     : editing_cell; //верхняя граница
}