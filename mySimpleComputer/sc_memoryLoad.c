//загружает из указанного файла содержимое оперативной памяти. Если передан
//неверный указатель на имя файла или произошла какая-либо ошибка чтения данных
//из файла, то функция завершается со статусом -1, при этом содержимое
//«оперативной памяти» никак не изменяется
#include "../include/mySimpleComputer.h"
#include "sc.h"

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

int
sc_memoryLoad (char *filename)
{
  FILE *file = fopen (filename, "rb");
  if (file == NULL)
    {
      perror ("Error opening file");
      return -1;
    }

  int *tmp_mem = (int *)malloc (sizeof (int) * MEMORY_SIZE);
  if (tmp_mem == NULL)
    {
      perror ("Memory allocation error");
      fclose (file);
      return -1;
    }

  size_t read_cnt = fread (tmp_mem, sizeof (int), MEMORY_SIZE, file);
  if (read_cnt > MEMORY_SIZE)
    {
      perror ("Error reading file");
      fclose (file);
      free (tmp_mem);
      return -1;
    }

  fclose (file);

  free (memory);
  memory = tmp_mem;

  return 0;
}