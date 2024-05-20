#include <console.h>
#include <myReadkey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <stdio.h>
int
input_value (int address)
{
  // printTerm(address, 1, membuffer);
  int tmp;
  // rk_myTermRegime (1, 1, 1, 1, 1);
  rk_myTermRestore ();
  print_message ("Введите значение: ");
  gui_refresh_flag = 0;
  scanf ("%d", &tmp);
  // rk_myTermRegime (0, 0, 1, 0, 1);

  if (sc_memorySet (address, tmp) == -1)
    {
      return -1;
    }

  /// in_out[0] = "> " tmp;

  return 0;
}