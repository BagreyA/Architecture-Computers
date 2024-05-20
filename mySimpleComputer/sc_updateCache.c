//Обновляет кеш
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stddef.h>
#include <time.h>

void
sc_updateCache (int memaddress, int cacheLine, int *value)
{
  static int currentIndex = 0;
  static int countIt = 0;
  if (updateCacheFlag == true)
    {
      currentIndex = 0;
      countIt = 0;
      updateCacheFlag = false;
    }

  *value = memory[memaddress];

  int address = (cacheLine / 10) * 10;
  int isInCache = false;

  for (int i = 0; i < CACHE_SIZE; ++i)
    {
      if (cache[i].address == address)
        {

          isInCache = true;
          currentIndex = i;
          break;
        }
    }

  if (!isInCache)
    {
      if (countIt < CACHE_SIZE)
        {
          currentIndex = countIt;
          for (int j = 0; j < CACHE_LINE_SIZE; ++j)
            {
              cache[currentIndex].data[j] = memory[address + j];
            }
          cache[currentIndex].address = address;
          cache[currentIndex].lastAccessTime = time (NULL);
          countIt++;
        }
      else
        {
          // Если кеш полон, заменяем наименее используемую запись
          currentIndex = sc_oldCacheGet ();
          for (int j = 0; j < CACHE_LINE_SIZE; ++j)
            {
              memory[cache[currentIndex].address + j]
                  = cache[currentIndex].data[j];
            }
          for (int j = 0; j < CACHE_LINE_SIZE; ++j)
            {
              cache[currentIndex].data[j] = memory[address + j];
            }
          cache[currentIndex].address = address;
          cache[currentIndex].lastAccessTime = time (NULL);
        }
    }
  else
    {
      // Если было попадание в кеш, обновляем существующую запись
      for (int j = 0; j < CACHE_LINE_SIZE; ++j)
        {
          cache[currentIndex].data[j] = memory[address + j];
        }
      cache[currentIndex].lastAccessTime = time (NULL);
    }
}