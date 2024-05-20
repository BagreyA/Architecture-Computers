//Инициализирует массив кеша
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdlib.h>

#include <stddef.h>

void
sc_initCache (void)
{
  cache = (struct L1 *)malloc (CACHE_SIZE * sizeof (struct L1));
  if (cache == NULL)
    {
      return;
    }

  for (int i = 0; i < CACHE_SIZE; ++i)
    {
      cache[i].address = -1;
      cache[i].lastAccessTime = 0;
      for (int j = 0; j < CACHE_LINE_SIZE; j++)
        {
          cache[i].data[j] = 0;
        }
    }
}