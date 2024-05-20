#include <mySimpleComputer.h>
#include <stdio.h>

int
edit_counter (void)
{
  int tmp;
  printf ("Введите новое значение счетчика: ");
  scanf ("%d", &tmp);
  return sc_icounterSet (tmp);
}