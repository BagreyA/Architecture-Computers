//визуализация интерфейса
#include <console.h>
#include <myBigChars.h>
#include <myReadkey.h>
#include <mySimpleComputer.h>

void
render_gui (void)
{
  mt_clrscr ();

  fflush (stdin);
  fflush (stdout);

  printMemory ();
  draw_blocks ();

  printBigCell ();
  printAccumulator ();
  printCommand ();
  printCounters ();
  printDecodedCommand (memory[editing_cell]);
  printFlags ();
  printTerm (editing_cell, 0, membuffer);
  printCache ();

  mt_gotoXY (0, 30);
}