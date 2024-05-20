#include <mySimpleComputer.h>
#include <stdio.h>

int
edit_acc (void)
{
  int tmp;
  printf ("Введите новое значение аккумулятора: ");
  scanf ("%d", &tmp);
  return sc_accumulatorSet (tmp);
}