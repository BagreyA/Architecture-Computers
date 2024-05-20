#include "myReadkey.h"
#include "rk.h"

int
rk_myTermSave ()
{
  if (tcgetattr (0, &termTemp))
    return -1;
  return 0;
}