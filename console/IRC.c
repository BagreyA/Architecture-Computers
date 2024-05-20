// реализует алгоритм работы контроллера прерываний
#include <console.h>
#include <myBigChars.h>
#include <myReadkey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>
#include <signal.h>

void
IRC (int signum)
{

  int CX = 0;
  sc_icounterGet (&CX);

  int flag_value = 0;

  switch (signum)
    {
    case SIGALRM:
      sc_regGet (IGNORE_SIGNAL_FLAG, &flag_value);
      if (flag_value == 1)
        return;

      editing_cell = CX;
      render_gui ();
      CU ();
      alarm (1);
      rk_myTermRegime (0, 1, 1, 0, 0);
      break;

    case SIGUSR1:
      // rk_myTermSave ();
      sc_regSet (IGNORE_SIGNAL_FLAG, 1);
      init_default ();
      break;
    default:
      break;
    }
}