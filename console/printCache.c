//вывод содержимого кэша
#include <console.h>
#include <mySimpleComputer.h>
#include <stdio.h>

void
printCache (void)
{
  for (int i = 0; i < CACHE_SIZE; ++i)
    {
      mt_gotoXY (2, 20 + i);

      if (cache[i].address == -1)
        {
          printf ("-");
        }
      else
        {
          printf ("%02d:", cache[i].address);
          for (int j = 0; j < CACHE_LINE_SIZE; ++j)
            {
              if ((cache[i].data[j] >> 14) & 1)
                {
                  if ((cache[i].data[j] >> 13) & 1)
                    printf (" -%04X", ~(cache[i].data[j] - 1) & 0x1FFF);
                  else
                    printf ("  %04X", cache[i].data[j] & 0x1FFF);
                }

              else
                {
                  printf (" +%04X", cache[i].data[j] & 0x1FFF);
                }
            }
        }
    }
  return;
}