//сохраняет содержимое памяти в файл в бинарном виде. Если передан неверный
//указатель на имя файла или произошла какая-либо ошибка записи данных в файл,
//то функция завершается со статусом -1. В случае успеха функция завершается со
//статусом 0;
#include "../include/mySimpleComputer.h"
#include "sc.h"

#include <stdio.h>

int
sc_memorySave (char *filename)
{
  FILE *file = fopen (filename, "wb");
  if (file == NULL)
    {
      perror ("Error opening file");
      return -1;
    }

  size_t write_cnt = fwrite (memory, sizeof (memory[0]), MEMORY_SIZE, file);
  if (write_cnt < MEMORY_SIZE)
    {
      perror ("Error writing to file");
      fclose (file);
      return -1;
    }

  fclose (file);

  return 0;
}