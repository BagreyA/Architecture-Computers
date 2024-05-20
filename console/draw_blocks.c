#include "../include/myBigChars.h"
#include "console.h"
#include <stdio.h>

void
draw_blocks (void)
{
  bc_box (0, 0, 62, 16, WHITE, BLACK, "\t Оперативная память ", RED, BLACK);
  bc_box (0, 16, 62, 3, WHITE, BLACK, "\t Редактируемая ячейка (формат) ", RED,
          WHITE);
  bc_box (62, 0, 26, 4, WHITE, BLACK, "\t Аккумулятор ", RED, BLACK);
  bc_box (88, 0, 25, 4, WHITE, BLACK, "\t Регистр флагов ", RED, BLACK);
  bc_box (62, 4, 26, 3, WHITE, BLACK, "\t Счётчик команд ", RED, BLACK);
  bc_box (88, 4, 25, 3, WHITE, BLACK, "\t Команда ", RED, BLACK);
  bc_box (62, 7, 51, 12, WHITE, BLACK,
          "\t\t\t Редактируемая ячейка (увеличено) ", RED, WHITE);
  bc_box (0, 19, 68, 7, WHITE, BLACK, "\t Кэш процессора ", GREEN, WHITE);
  bc_box (68, 19, 13, 7, WHITE, BLACK, " IN--OUT ", GREEN, WHITE);
  bc_box (81, 19, 32, 7, WHITE, BLACK, "\t Клавиши ", GREEN, WHITE);

  mt_gotoXY (83, 20);
  printf ("l - load s - save i - reset");
  mt_gotoXY (83, 21);
  printf ("r - run t - step");
  mt_gotoXY (83, 22);
  printf ("ESC - exit");
  mt_gotoXY (83, 23);
  printf ("F5 - accumulator");
  mt_gotoXY (83, 24);
  printf ("F6 - instruction counter");

  mt_gotoXY (63, 17);
  mt_setfgcolor (CYAN);
  printf (" Номер редактируемой ячейки: %d ", editing_cell);
  return;
}