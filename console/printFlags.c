//выводит значения флагов в нужном месте экрана
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdio.h>

void
printFlags (void)
{
  int x_pos = 98;

  const char *letters = "P0MTE";
  for (int i = 0; i < 5; i++)
    {
      int val = 0;
      sc_regGet (i, &val);

      mt_gotoXY (x_pos + i * 2, 2);
      if (val != 0)
        {
          printf ("%c", (unsigned char)letters[i]);
        }
      else
        {
          printf ("_");
        }
    }
}