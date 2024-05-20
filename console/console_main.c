#include <console.h>
#include <fcntl.h>
#include <myBigChars.h>
#include <myReadkey.h>
#include <mySimpleComputer.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main (void)
{
  if (!isatty (fileno (stdout)))
    {
      fprintf (stderr, "Error: output stream shoud be stdout.\n");
      return 1;
    }

  int console_w = 0;
  int console_h = 0;
  mt_getscreensize (&console_h, &console_w);

  if (console_h < 24 || console_w < 130)
    {
      printf ("Error: Terminal doesn't fit 24x100.\n");
      return 1;
    }
  //Устанавливает буферизацию для стандартного потока вывода
  setbuf (stdout, NULL);

  mt_clrscr ();

  init_default ();

  int fd = open ("./fontGenerator/font.out", O_WRONLY);
  bc_bigcharwrite (fd, *bc, 18);
  close (fd);

  rk_myTermSave ();

  enum keys key;
  char path[64];
  int exit_flag = 0;
  int flag_value = 0;
  int x, y;
  //Устанавливает обработчики сигналов
  signal (SIGALRM, IRC);
  signal (SIGUSR1, IRC);
  //работа с терминалом: флаги, обновление интерфейса, клавиши и т.д
  while (!exit_flag)
    {
      sc_regGet (IGNORE_SIGNAL_FLAG, &flag_value);

      if (flag_value == 0)
        {
          continue;
        }

      if (!gui_refresh_flag)
        render_gui ();

      rk_readKey (&key);

      fflush (stdin);
      fflush (stdout);

      switch (key)
        {
        case KEY_r:
          sc_regInit ();
          sc_regSet (IGNORE_SIGNAL_FLAG, 0);
          raise (SIGALRM);
          // alarm(0);
          break;

        case KEY_t:
          CU ();
          editing_cell = CX;
          break;

        case KEY_enter:
          x = editing_cell % 10;
          y = editing_cell / 10;
          mt_gotoXY ((x + 1) * 6 - 4, y + 2);
          unsigned int tmp;
          scanf ("%x", &tmp);
          if (sc_memorySet (editing_cell, tmp) != 0)
            {
              print_message ("Введено неправильное число!");
            };

          membuffer[in_out_ind].addr = editing_cell;
          membuffer[in_out_ind].buf = tmp;
          membuffer[in_out_ind].input = 1;
          in_out_ind = (in_out_ind + 1) % 4;
          break;

        case KEY_left:
          editing_cell--;
          validate_cell ();
          gui_refresh_flag = 0;
          break;

        case KEY_right:
          editing_cell++;
          validate_cell ();
          gui_refresh_flag = 0;
          break;

        case KEY_up:
          editing_cell -= 10;
          validate_cell ();
          gui_refresh_flag = 0;
          break;

        case KEY_down:
          editing_cell += 10;
          validate_cell ();
          gui_refresh_flag = 0;
          break;

        case KEY_f5:
          edit_acc ();
          gui_refresh_flag = 0;
          break;

        case KEY_f6:
          edit_counter ();
          gui_refresh_flag = 0;
          break;

        case KEY_esc:
          exit (0);
          break;

        case KEY_s:
          print_message ("[Сохранить память] Введите имя файла: ");
          scanf ("%s", path);
          if (sc_memorySave (path) == -1)
            {
              print_message ("Ошибка при сохранении памяти...");
            }
          else
            {
              print_message ("Сохранен!");
            };
          gui_refresh_flag = 1;
          break;

        case KEY_l:
          print_message ("[Загрузить память] Введите имя файла:");
          scanf ("%s", path);
          if (sc_memoryLoad (path) == -1)
            {
              gui_refresh_flag = 1;
              continue;
            }
          gui_refresh_flag = 0;
          break;

        case KEY_i:
          raise (SIGUSR1);
          break;

        default:
          break;
        }
    }

  mt_clrscr ();
  return 0;
}