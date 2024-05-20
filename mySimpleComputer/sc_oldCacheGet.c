//Находит наименее используемую строку кеша
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <time.h>

int
sc_oldCacheGet (void)
{
  int cacheIndex = 0;
  time_t lastUsed = cache[0].lastAccessTime;
  for (int i = 1; i < CACHE_SIZE; ++i)
    {
      if (cache[i].lastAccessTime < lastUsed)
        {
          lastUsed = cache[i].lastAccessTime;
          cacheIndex = i;
        }
    }
  return cacheIndex;
}