//выводит на экран псевдографическую рамку
#include <myBigChars.h>
#include <myTerm.h>
#include <stdio.h>
#include <string.h>

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  if (!(x1 >= 0 || y1 >= 0 || (x2 + x1) > x1 || (y2 + y1) > y1))
    {

      return -1;
    }

  if (header != NULL)
    {
      mt_setfgcolor (box_fg);
      mt_setbgcolor (box_bg);

      for (int i = 1; i < x2 - 1; i++)
        {
          mt_gotoXY (x1 + i, y1);
          bc_printA (ACS_HLINE);
          mt_gotoXY (x1 + i, y1 + y2 - 1);
          bc_printA (ACS_HLINE);
        }

      for (int i = 1; i < y2 - 1; i++)
        {
          mt_gotoXY (x1, y1 + i);
          bc_printA (ACS_VLINE);
          mt_gotoXY (x1 + x2 - 1, y1 + i);
          bc_printA (ACS_VLINE);
        }

      mt_gotoXY (x1, y1);
      bc_printA (ACS_ULCORNER);
      mt_gotoXY (x1 + x2 - 1, y1);
      bc_printA (ACS_URCORNER);
      mt_gotoXY (x1, y1 + y2 - 1);
      bc_printA (ACS_LLCORNER);
      mt_gotoXY (x1 + x2 - 1, y1 + y2 - 1);
      bc_printA (ACS_LRCORNER);

      mt_gotoXY (x1 + (x2 - strlen (header)) / 2, y1);
      mt_setfgcolor (header_fg);
      mt_setbgcolor (header_bg);
      printf ("%s", header);
      mt_setdefaultcolor ();
    }
  return 1;
}