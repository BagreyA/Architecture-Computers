#include <stdio.h>

int bc[16][2];

int
main ()
{
  //Открыть файл для записи в двоичном режиме
  FILE *outfile = fopen ("font.bin", "wb");
  if (outfile == NULL)
    {
      perror ("Error opening file");
      return 1;
    }

  //Запишите каждый элемент массива в файл
  for (int i = 0; i < sizeof (bc) / sizeof (bc[0]); ++i)
    {
      for (int j = 0; j < sizeof (bc[0]) / sizeof (bc[0][0]); ++j)
        {
          fwrite (&bc[i][j], sizeof (bc[0][0]), 1, outfile);
        }
    }

  //Закрыть файл
  fclose (outfile);

  printf ("Data has been written to font.bin successfully.\n");

  return 0;
}
