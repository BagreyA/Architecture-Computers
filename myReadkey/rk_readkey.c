#include "myReadkey.h"
int
rk_readKey (enum keys *key)
{
  char buf[16];
  int num_read;

  rk_myTermRegime (0, 30, 0, 0, 0);
  num_read = read (STDIN_FILENO, buf, 15);
  rk_myTermRestore ();

  if (num_read < 0)
    return -1;

  buf[num_read] = '\0';

  if (strcmp (buf, "l") == 0)
    *key = KEY_l;
  else if (strcmp (buf, "s") == 0)
    *key = KEY_s;
  else if (strcmp (buf, "r") == 0)
    *key = KEY_r;
  else if (strcmp (buf, "t") == 0)
    *key = KEY_t;
  else if (strcmp (buf, "i") == 0)
    *key = KEY_i;
  else if (strcmp (buf, "q") == 0)
    *key = KEY_q;
  else if (strcmp (buf, "\n") == 0)
    *key = KEY_enter;
  else if (strcmp (buf, "\033[15~") == 0)
    *key = KEY_f5;
  else if (strcmp (buf, "\033[17~") == 0)
    *key = KEY_f6;
  else if (strcmp (buf, "\033[A") == 0)
    *key = KEY_up;
  else if (strcmp (buf, "\033[B") == 0)
    *key = KEY_down;
  else if (strcmp (buf, "\033[C") == 0)
    *key = KEY_right;
  else if (strcmp (buf, "\033[D") == 0)
    *key = KEY_left;
  else if (strcmp (buf, "\033") == 0)
    *key = KEY_esc;
  else
    *key = KEY_other;

  return 0;
}