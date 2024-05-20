#include "../../include/mySimpleComputer.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main (void)
{
  setlocale (LC_ALL, "ru_RU.UTF-8");
  srand (time (NULL));

  sc_memoryInit ();
  sc_regInit ();
  for (int i = 0; i < rand (); i++)
    {
      sc_memorySet (i, rand () % 1000);
    }
  for (int i = 0; i < 10; i++)
    {
      int val = 0;
      sc_memoryGet (i, &val);
      printf ("%d ", val);
    }

  int memset_st = sc_memorySet (0, 1e5);
  if (memset_st)
    {
      printf ("\nError setting incorrect value!\nResult: %d\n", memset_st);
    }

  for (int i = 0; i < 5; i++)
    {
      sc_regSet (i, rand () % 2);
    }
  printFlags ();
  int flag_st = sc_regSet (6, rand () % 2);
  if (flag_st)
    {
      printf ("\nError setting incorrect flag value!\nResult: %d\n", flag_st);
    }

  sc_accumulatorSet (55);
  printAccumulator ();
  int acc_st = sc_accumulatorSet (1e6);
  if (acc_st)
    {
      printf ("\nError setting incorrect accumulator value!\nResult: %d\n",
              acc_st);
    }

  int com_st = sc_icounterSet (1e6);
  if (com_st)
    {
      printf (
          "\nError setting incorrect command register value!\nResult: %d\n",
          com_st);
    }

  int rnd_mem_val = 0;
  int acc_val = 0;
  sc_memoryGet (rand () % MEMORY_SIZE, &rnd_mem_val);
  sc_accumulatorGet (&acc_val);
  printDecodedCommand (rnd_mem_val);
  printDecodedCommand (acc_val);

  int cmd = 0;
  sc_commandEncode (1, 10, 1, &cmd);
  printDecodedCommand (cmd);
  printf ("\n");
  return 0;
}