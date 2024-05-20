//алгоритм работы одного такта устройства управления.
#include <commands.h>
#include <console.h>
#include <mySimpleComputer.h>
#include <signal.h>
#include <stdio.h>

void
CU (void)
{
  int sign, command, operand;
  int tempValue, tempValue1;
  char buff[32] = { 0 };

  int accumulator = 0;
  sc_accumulatorGet (&accumulator);

  int commandCounter = 0;
  sc_icounterGet (&commandCounter);

  int memValue = 0;
  if (sc_memoryGet (commandCounter, &memValue) != 0)
    {
      sc_regSet (MEMORY_OUT_FLAG, 1);
      sc_regSet (IGNORE_SIGNAL_FLAG, 1);
      return;
    }

  if (sc_commandDecode (memValue, &sign, &command, &operand) != 0)
    {
      sc_regSet (WRONG_COMMAND_FLAG, 1);
      sc_regSet (IGNORE_SIGNAL_FLAG, 1);
      return;
    }
  if ((operand < 0) && (operand >= MEMORY_SIZE - 1))
    {
      sc_regSet (WRONG_COMMAND_FLAG, 1);
      sc_regSet (IGNORE_SIGNAL_FLAG, 1);
      return;
    }
  if ((command >= 30) && (command <= 33))
    {
      if (ALU (command, operand) != 0)
        sc_regSet (IGNORE_SIGNAL_FLAG, 1);
    }
  else
    {
      switch (command)
        {
        case NOP:
          break;
        case CPUINFO:
          print_message ("Bagrey Anastasia Olegovna IA-232");
          break;
        case READ:
          while (input_value (operand) != 0)
            {
            };
          membuffer[in_out_ind].addr = operand;
          membuffer[in_out_ind].buf = memory[operand];
          membuffer[in_out_ind].input = 1;
          in_out_ind = (in_out_ind + 1) % 4;
          printTerm (operand, 1, membuffer);
          break;
        case WRITE:
          if (sc_memoryGet (operand, &memValue) != 0)
            {
              sc_regSet (MEMORY_OUT_FLAG, 1);
              sc_regSet (IGNORE_SIGNAL_FLAG, 1);
              return;
            }

          sscanf (buff, "%d", &memValue);
          membuffer[in_out_ind].addr = operand;
          membuffer[in_out_ind].buf = memValue;
          membuffer[in_out_ind].input = 0;
          in_out_ind = (in_out_ind + 1) % 4;
          printTerm (commandCounter, 0, membuffer);
          break;

        case LOAD:
          if (sc_memoryGet (operand, &memValue) != 0)
            {
              sc_regSet (MEMORY_OUT_FLAG, 1);
              sc_regSet (IGNORE_SIGNAL_FLAG, 1);
              return;
            }
          sc_accumulatorSet (memValue);
          break;

        case STORE:
          sc_memorySet (operand, accumulator);
          break;

        case JUMP:
          sc_icounterSet (operand);
          return;
          break;

        case JNEG:
          if (accumulator < 0)
            {
              sc_icounterSet (operand);
              return;
            }
          break;

        case JZ:
          if (accumulator == 0)
            {
              sc_icounterSet (operand);
              return;
            }
          break;

        case NOT:
          accumulator = ~accumulator;
          sc_accumulatorSet (accumulator);
          sc_memorySet (operand, accumulator);
        case AND:
          sc_memoryGet (operand, &tempValue);
          accumulator &= tempValue;
          sc_accumulatorSet (accumulator);
        case OR:
          sc_memoryGet (operand, &tempValue);
          accumulator |= tempValue;
          sc_accumulatorSet (accumulator);
          break;
        case XOR:
          sc_memoryGet (operand, &tempValue);
          accumulator ^= tempValue;
          sc_accumulatorSet (accumulator);
          break;
        case JNS:
          if (accumulator > 0)
            {
              sc_icounterSet (operand);
              return;
            }
          break;
        case JNP:
          if (accumulator % 2 != 0)
            {
              sc_icounterSet (operand);
              return;
            }
          break;
        case JP:
          if (accumulator % 2 == 0)
            {
              sc_icounterSet (operand);
              return;
            }
          break;
        case CHL:
          //Логика сдвига влево
          break;
        case SHR:
          //Сдвинуть логику вправо
          break;
        case RCL:
          //Логический поворот влево
          break;
        case RCR:
          //Логический поворот вправо
          break;
        case NEG:
          accumulator = -accumulator;
          sc_accumulatorSet (accumulator);
          break;
        case LOGLC:
          //Логический сдвиг кода влево
          break;
        case LOGRC:
          //Логический сдвиг правого кода
          break;
        case RCCL:
          //Поверните влево через переноску
          break;
        case RCCR:
          //Поверните прямо через переноску
          break;
        case MOVA:
          sc_memoryGet (operand, &tempValue);
          sc_memorySet (accumulator, tempValue);
          break;
        case MOVR:
          sc_memoryGet (accumulator, &tempValue);
          sc_memorySet (operand, tempValue);
          break;
        case MOVCA:
          //Перемещение с косвенной адресацией из A
          break;
        case MOVCR:
          //Перейти с косвенной адресацией к R
          break;
        case ADDC:
          sc_memoryGet (accumulator, &tempValue);
          sc_memoryGet (operand, &tempValue1);
          sc_accumulatorSet (tempValue + tempValue1);
          break;
        case SUBC:
          sc_memoryGet (accumulator, &tempValue);
          sc_memoryGet (operand, &tempValue1);
          sc_accumulatorSet (tempValue - tempValue1);
          break;

        case HALT:
          raise (SIGUSR1);
          break;
        default:
          sc_regSet (WRONG_COMMAND_FLAG, 1);
          sc_regSet (IGNORE_SIGNAL_FLAG, 1);
          return;
        };
    }

  if (sc_icounterSet (commandCounter + 1) != 0)
    {
      sc_regSet (MEMORY_OUT_FLAG, 1);
      sc_regSet (IGNORE_SIGNAL_FLAG, 1);

      return;
    }
}