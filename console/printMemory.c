//вывод содержимого памяти
#include <console.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <stdio.h>

void
printMemory (void)
{
  int i, j;
  int sign;
  for (i = 0; i < 13; i++)
    {
      mt_gotoXY (2, 2 + i);
      for (j = 0; j < 10; j++)
        {
          int index = i * 10 + j;
          if (index > MEMORY_SIZE - 1)
            break;

          sign = (memory[index] >> 14) & 1;

          if (index == editing_cell)
            {
              mt_setfgcolor (BLACK);
              mt_setbgcolor (WHITE);
            }

          if (sign == 0)
            printf ("+%04X", memory[index]);
          else
            printf ("-%04X", memory[index] & 0xFFFF);

          if (index == editing_cell)
            {
              mt_setdefaultcolor ();
            }

          if (j != 9)
            printf (" ");
        }
    }
}