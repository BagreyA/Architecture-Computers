//выводит значения в нужно месте экрана (блок «Редактируемая ячейка (формат)»)
#include "../include/myTerm.h"
#include <stdio.h>

void
printDecodedCommand (int value)
{
  mt_gotoXY (2, 17);

  printf ("dec: %d | ", value);
  printf ("oct: %o | ", value);
  printf ("hex: %x | ", value);

  printf ("bin: ");
  for (int i = 14; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
  printf ("\n");
}