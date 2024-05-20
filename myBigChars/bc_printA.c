//выводит строку символов с использованием дополнительной кодировочной таблицы
#include <myBigChars.h>
#include <stdio.h>

int
bc_printA (char str)
{
  printf ("\033(0%c\033(B", str);
  return 0;
}