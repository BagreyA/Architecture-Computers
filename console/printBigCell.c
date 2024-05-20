#include <console.h>
#include <myBigChars.h>
#include <mySimpleComputer.h>

void
printBigCell (void)
{
  int tmp = 0;
  sc_memoryGet (editing_cell, &tmp);
  if ((tmp >> 14) & 1)
    // +
    bc_printbigchar (bc[17], 63, 9, WHITE, BLACK);
  else
    // -
    bc_printbigchar (bc[16], 63, 9, WHITE, BLACK);

  for (int i = 0; i < 4; ++i)
    {
      int ch = (tmp & (15 << (4 * (3 - i)))) >> (4 * (3 - i));

      bc_printbigchar (bc[ch], 62 + 8 * (i + 1) + 2 * (i + 1), 9, WHITE,
                       BLACK);
    }

  return;
}