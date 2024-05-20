//выводит значение ячейки памяти с учетом заданных цветов символов и фона.
//Местоположение выводимого значения рассчитывается исходя из заданного адреса
//ячейки памяти и расположения блока «Оперативная память»
#include "../include/mySimpleComputer.h"
#include "sc.h"
#include <stdio.h>
#include <unistd.h>

void
printCell (int address, enum colors fg, enum colors bg)
{
  int value = 0;
  sc_memoryGet (address, &value);
  const int cols_size = 10;

  int col = address % cols_size;
  int row = address / cols_size;

  mt_gotoXY ((col * 6) + 2, (row + 1) + 1);

  mt_setfgcolor (fg);
  mt_setbgcolor (bg);

  int is_pos = (((value & 0x8000) >> 15) == 0);
  char sign_char = (is_pos ? '+' : '-');
  printf ("%c%04d\n", sign_char, value);

  mt_setdefaultcolor ();
}