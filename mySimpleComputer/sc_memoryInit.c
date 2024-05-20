//инициализирует оперативную память Simple Computer, задавая всем её ячейкам
//нулевые значения
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdlib.h>

int
sc_memoryInit (void)
{
  memory = (int *)malloc (MEMORY_SIZE * sizeof (int));
  if (memory == NULL)
    return -1;

  for (int i = 0; i < MEMORY_SIZE; i++)
    {
      memory[i] = 0;
    }

  return 0;
}