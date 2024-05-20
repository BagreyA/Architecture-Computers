//алгоритм работы одного такта арифметико-логического устройства
#include <console.h>
#include <mySimpleComputer.h>

int
ALU (int command, int operand)
{
  int accumulator = 0;
  sc_accumulatorGet (&accumulator);

  int commandCounter = 0;
  sc_icounterGet (&commandCounter);

  int value = 0;
  if (sc_memoryGet (operand, &value) == -1)
    {
      sc_regSet (MEMORY_OUT_FLAG, 1);
      return -1;
    }

  switch (command)
    {
    case 0x1E: // ADD
      if (sc_accumulatorSet (accumulator + value) == -1)
        {
          sc_regSet (OVERFLOW_FLAG, 1);
          return -1;
        }
      break;
    case 0x1F: // SUB
      if (sc_accumulatorSet (accumulator - value) == -1)
        {
          sc_regSet (OVERFLOW_FLAG, 1);
          return -1;
        }
      break;
    case 0x20: // DIV
      if (value == 0)
        {
          sc_regSet (ZERO_DIVISION_FLAG, 1);
          return -1;
        }
      if (sc_accumulatorSet (accumulator / value) == -1)
        {
          sc_regSet (OVERFLOW_FLAG, 1);
          return -1;
        }
      break;
    case 0x21: // MUL
      if (sc_accumulatorSet (accumulator * value) == -1)
        {
          sc_regSet (OVERFLOW_FLAG, 1);
          return -1;
        }
      break;
    default:
      return -1;
    }

  return 0;
}