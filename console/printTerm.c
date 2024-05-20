//выводит очередную строку в блок “IN—OUT”
#include "../include/mySimpleComputer.h"
#include "./console.h"
#include <stdio.h>
#include <stdlib.h>

void
printTerm (int address, int input, struct memBuffer *buffer)
{
  for (int i = 0; i < 4; i++)
    {
      mt_gotoXY (69, 20 + i);
      printf ("%d ", buffer[i].addr);
      if (buffer[i].input)
        printf ("< ");
      else
        printf ("> ");

      if ((buffer[i].buf >> 14) & 1)
        {
          if ((buffer[i].buf >> 13) & 1)
            printf ("-%04X", (~(buffer[i].buf - 1)));
          else
            printf ("+%04X", buffer[i].buf);
        }
      else
        {
          printf ("+%04X", buffer[i].buf);
        }
    }
}