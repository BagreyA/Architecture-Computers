//инициализация по умолчанию
#include <console.h>
#include <mySimpleComputer.h>

void
init_default (void)
{
  editing_cell = 0;
  sc_memoryInit ();
  sc_icounterInit ();
  sc_regInit ();
  sc_initCache ();
}